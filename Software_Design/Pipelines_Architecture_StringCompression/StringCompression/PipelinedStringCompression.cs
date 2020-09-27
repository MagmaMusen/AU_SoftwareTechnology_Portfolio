using System;
using System.Collections.Concurrent;
using System.Linq;
using System.Threading.Tasks;

namespace StringCompression
{
    internal class PipelinedStringCompression
    {
        private readonly int _nStrings;
        private readonly int _stringLength;
        private readonly string _charsInString;

        double _avgCompressionRatio = 0;

        public PipelinedStringCompression(string charsInString, int nStrings, int stringLength)
        {
            _charsInString = charsInString;
            _nStrings = nStrings;
            _stringLength = stringLength;
        }

        struct CompressedStringInfo
        {
            public string original;
            public string compressed;
        };

        BlockingCollection<string> generatedStringQueue = new BlockingCollection<string>();
        BlockingCollection<CompressedStringInfo> compressedStringQueue = new BlockingCollection<CompressedStringInfo>();
        
        public double Run()
        {
            // create and start tasks
            Task generateStringsTask = Task.Run(() => GenerateStringsStage(_nStrings, _stringLength, generatedStringQueue));
            Task compressionTask = Task.Run(() => CompressStringsStage(generatedStringQueue, compressedStringQueue));
            Task updateCompressionStatsTask = Task.Run(() => UpdateCompressionStatsStage(compressedStringQueue, ref _avgCompressionRatio));

            Task.WaitAll(generateStringsTask, compressionTask, updateCompressionStatsTask);

            return _avgCompressionRatio;
        }

        private void GenerateStringsStage(int numberOfStrings, int stringLength, BlockingCollection<string> output)
        {
            try
            {
                for (int i = 0; i < numberOfStrings; i++)
                {
                    var str = Generate(stringLength);
                    output.Add(str);
                }
            }
            finally
            {
                output.CompleteAdding();
            }
        }

        private void CompressStringsStage(BlockingCollection<string> input, BlockingCollection<CompressedStringInfo> output)
        {
            try
            {
                foreach (string str in input.GetConsumingEnumerable())
                {
                    var compressedStr = Compress(str);
                    CompressedStringInfo strInfo = new CompressedStringInfo();
                    strInfo.original = str;
                    strInfo.compressed = compressedStr;
                    output.Add(strInfo);
                }
            }
            finally
            {
                output.CompleteAdding();
            }
        }

        private void UpdateCompressionStatsStage(BlockingCollection<CompressedStringInfo> input, ref double compressionRatio)
        {
            try
            {
                int i = 0;
                foreach (CompressedStringInfo info in input.GetConsumingEnumerable())
                {
                    compressionRatio = UpdateCompressionStats(i, info.original, info.compressed);
                }
            }
            finally
            {

            }
        }

        private double UpdateCompressionStats(int i, string str, string compressedStr)
        {
            _avgCompressionRatio = ((i * _avgCompressionRatio) + ((double)(compressedStr.Length) / str.Length)) / (i + 1);
            return _avgCompressionRatio;
        }


        private string Compress(string str)
        {
            var result = "";
            for (var i = 0; i < str.Length; i++)
            {
                var j = i;
                result += str[i];
                while ((j < str.Length) && (str[i] == str[j]))
                    j++;

                if (j > i + 1)
                {
                    result += (j - i);
                    i = j - 1;
                }
            }
            return result;
        }

        private string Generate(int stringLength)
        {
            var random = new Random();
            var result = new string(Enumerable.Repeat(_charsInString, stringLength).Select(s => s[random.Next(s.Length)]).ToArray());
            return result;
        }
    }
}

