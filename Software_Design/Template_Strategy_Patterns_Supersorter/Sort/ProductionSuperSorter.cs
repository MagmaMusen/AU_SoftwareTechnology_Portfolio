namespace supersorter.Sort
{
    public class ProductionSuperSorter : SuperSorter
    {

        public ProductionSuperSorter(int[] unsorted): base(unsorted) {
        }

        protected override void Start() {
        }

        protected override long Stop() {
            return 0;

        }
    }
}