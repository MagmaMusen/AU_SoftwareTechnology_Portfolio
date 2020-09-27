using System;

using supersorter.Generators;
using supersorter.Sort;

namespace supersorter
{
    class Program
    {
        static void Main(string[] args)
        {
            var size = 10;
            var seed = 123456789;
            if (args.Length > 0) {
                size = int.Parse(args[0]);
            }
            if (args.Length > 1) {
                seed = int.Parse(args[1]);
            }
            

            var experiment = new Experiment(size, seed);
            experiment.Run();
        }
    }

    public class Experiment {
        private int _size;
        private int _seed;
        private const int MAX_VALUE = 1000000;

        private ISort[] sorters;
        private IArrayGenerator[] generators;
        public Experiment(int size, int seed) {
            _size = size;
            _seed = seed;

            generators = new IArrayGenerator[] {
                new RandomArrayGenerator(_size, MAX_VALUE, _seed),
                new NearlySortedGenerator(_size, MAX_VALUE, _seed),
                new ReverseOrderGenerator(_size, MAX_VALUE),
                new FewValuesGenerator(_size, _seed)
            };

            sorters = new ISort[] {
                new BubbleSort(),
                new InsertionSort(),
                new ShellSort(),
            };
        }

        public void Run() {
            long time;
            foreach(var g in generators) {
                var superSorter = new ExperimentSuperSorter(g.Generate());
                foreach(var s in sorters) {
                    superSorter.Sort(s, out time);
                    Console.WriteLine($"Sorted {_size} ints from '{g}' in {time}ms with '{s}'.");
                }
            }
        }
    }
}
