using System;
namespace supersorter.Generators
{
    public class RandomArrayGenerator : IArrayGenerator
    {
        private Random ran;
        private int _size;
        private int _max;
        
        public RandomArrayGenerator(int size, int max, int seed) {
            _size = size;
            _max = max;
            ran = new Random(seed);
        }

        public int[] Generate() {
            int[] data = new int[_size];

            for (var i = 0; i < _size; i++) {
                data[i] = ran.Next(_max);
            }

            return data;
        }

        public override string ToString() {
            return "RandomValues";
        }
    }
}