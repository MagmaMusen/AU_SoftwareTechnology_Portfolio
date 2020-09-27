namespace supersorter.Generators
{
    public class ReverseOrderGenerator : IArrayGenerator
    {
        private int _size;
        private int _max;
        
        public ReverseOrderGenerator(int size, int max) {
            _size = size;
            _max = max;
        }

        public int[] Generate() {
            int[] data = new int[_size];

            for (var i = 0; i < _size; i++) {
                data[i] = _size - i;
            }

            return data;
        }

        public override string ToString() {
            return "ReverseOrderValues";
        }
    }
}