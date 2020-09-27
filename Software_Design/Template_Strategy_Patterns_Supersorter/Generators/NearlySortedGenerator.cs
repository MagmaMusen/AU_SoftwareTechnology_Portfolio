using System;
namespace supersorter.Generators
{
    public class NearlySortedGenerator : IArrayGenerator
    {
        private Random ran;
        private int _size;
        private int _max;

        public NearlySortedGenerator(int size, int max, int seed) {
            _size = size;
            _max = max;
            ran = new Random(seed);
        }

        public int[] Generate() {
            var unsorted = new int[_size];

            for (var i = 0; i < _size; i++) {
                if (ran.Next(5) == 1) {
                    unsorted[i] = ran.Next(_max);
                } else {
                    unsorted[i] = i;
                }
            }

            return unsorted;
        }

        public override string ToString() {
            return "NearlySortedValues";
        }
    }
}