namespace supersorter.Sort
{
    public abstract class SuperSorter
    {
        private int[] _unsorted;

        public SuperSorter(int[] unsorted) {
            _unsorted = unsorted;
        }

        public int[] Sort(ISort sort, out long elapsedMillies) {
            int[] data = (int[]) _unsorted.Clone();

            Start();
            var sorted = sort.Sort(data);
            elapsedMillies = Stop();
            return sorted;
        }

        protected abstract void Start();
        protected abstract long Stop();
    }
}