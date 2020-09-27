using System;
using System.Diagnostics;

namespace StringCompression
{
    class Program
    {
        const int NUMBER_OF_STRINGS = 100000;
        const int STRING_LENGHT = 500;

        static void Main(string[] args)
        {
            System.Console.WriteLine("Generating and compressing strings");
            var s1 = new Stopwatch();
            SequentialStringCompression comp = new SequentialStringCompression("abc", NUMBER_OF_STRINGS, STRING_LENGHT);
            s1.Start();
            double avgCompressionRatio = comp.Run();
            s1.Stop();
            System.Console.WriteLine("Average compression ratio: {0}", avgCompressionRatio);
            System.Console.WriteLine("Serial time in milliseconds: {0}", s1.ElapsedMilliseconds);

            s1.Reset();
            PipelinedStringCompression pipelinedComp = new PipelinedStringCompression("abc", NUMBER_OF_STRINGS, STRING_LENGHT);
            s1.Start();
            double avgPipelinedCompressionRatio = pipelinedComp.Run();
            s1.Stop();
            System.Console.WriteLine("Average compression ratio: {0}", avgPipelinedCompressionRatio);
            Console.WriteLine("Pipelined time in milliseconds: {0}", s1.ElapsedMilliseconds);

            s1.Reset();
            PipelinedStringCompressionWithMulitpleCompressors pipelinedMultiple = new PipelinedStringCompressionWithMulitpleCompressors("acb", NUMBER_OF_STRINGS, STRING_LENGHT);
            s1.Start();
            double avgPipelinedMultipleRatio = pipelinedMultiple.Run();
            s1.Stop();
            System.Console.WriteLine("Average compression ratio: {0}", avgPipelinedMultipleRatio);
            Console.WriteLine("Pipelined with multiple compressors time in milliseconds: {0}", s1.ElapsedMilliseconds);

        }
    }
}
