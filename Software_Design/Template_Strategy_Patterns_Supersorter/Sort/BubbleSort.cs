namespace supersorter.Sort
{
    public class BubbleSort : ISort
    {
        public int[] Sort(int[] unsorted) {
            var swapped = true;
            while (swapped) {
                swapped = false;
                for (var i = 0; i < unsorted.Length - 1; i++) {
                    if (unsorted[i]  > unsorted[i+1]) {
                        Swap(unsorted, i, i+1);
                        swapped = true;
                    }
                }
            }
            return unsorted;
        }

        public void Swap(int[] array, int i, int j) {
            var tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }

        public override string ToString() {
            return "BubbleSort";
        }
    }
}