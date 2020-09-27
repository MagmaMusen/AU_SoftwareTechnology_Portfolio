namespace supersorter.Sort
{
    public class ShellSort : ISort
    {
        ISortPart insertionSort;
        public ShellSort() {
            insertionSort = new InsertionSort();

        }

        public int[] Sort(int[] unsorted) {
            var gaps = new int[] { 701, 301, 132, 57, 23, 10, 4, 1 };

            foreach (var gap in gaps) {
                insertionSort.Sort(unsorted, gap, unsorted.Length);
            }

            return unsorted;
        }

        public override string ToString() {
            return "ShellSort";
        }
    }
}