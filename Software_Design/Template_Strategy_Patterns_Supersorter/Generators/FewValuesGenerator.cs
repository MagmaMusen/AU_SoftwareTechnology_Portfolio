using System.CodeDom.Compiler;
using System;

namespace supersorter.Generators
{
    public class FewValuesGenerator : IArrayGenerator
    {
        private Random ran;
        private int _size;
        
        public FewValuesGenerator(int size, int seed) {
            _size = size;
            ran = new Random(seed);
        }        
        public int[] Generate() {
            var data = new int[_size];

            for (var i = 0; i < _size; i++) {
                data[i] = ran.Next(10);
            }

            return data;
        }

        public override string ToString() {
            return "FewValues";
        }
    }
}