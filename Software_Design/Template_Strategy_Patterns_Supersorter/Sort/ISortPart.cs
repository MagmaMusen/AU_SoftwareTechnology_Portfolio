namespace supersorter.Sort
{
    public interface ISortPart
    {
        /**
            Sort part of the array in-place
         */
         void Sort(int[] data, int n, int m);
    }
}