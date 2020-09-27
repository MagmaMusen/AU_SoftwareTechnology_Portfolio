namespace supersorter.Sort
{
    public class InsertionSort : ISort, ISortPart
    {
        public int[] Sort(int[] unsorted) {
            Sort(unsorted, 1, unsorted.Length);
            return unsorted;
        }

        public void Sort(int[] data, int n, int m) {
            var i = n;
            while (i < m) {
                var j = i;
                while (j > 0 && data[j - 1] > data[j]) {
                    Swap(data, j, j-1);
                    j--;
                }
                i++;
            }
        }

        public void Swap(int[] array, int i, int j) {
            var tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }

        public override string ToString() {
            return "InsertionSort";
        }
    }
}