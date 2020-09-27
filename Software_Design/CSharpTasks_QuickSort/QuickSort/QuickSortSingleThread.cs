using System;
using System.Collections.Generic;
using System.Threading.Tasks;
namespace QuickSort
{
    public class QuickSortSingleThread
    {
        public static void SerialQuicksort(long[] elements, long left, long right)
        {
            long i = left, j = right;
            var pivot = elements[(left + right) / 2];

            while (i <= j)
            {
                while (elements[i].CompareTo(pivot) < 0) i++;
                while (elements[j].CompareTo(pivot) > 0) j--;

                if (i <= j)
                {
                    // Swap
                    var tmp = elements[i];
                    elements[i] = elements[j];
                    elements[j] = tmp;

                    i++;
                    j--;
                }
            }

            // Recursive calls
            if (left < j) SerialQuicksort(elements, left, j);
            if (i < right) SerialQuicksort(elements, i, right);
        }

        public static void TaskBasedQuicksort(long[] elements, long left, long right)
        {
            long i = left, j = right;
            var pivot = elements[(left + right) / 2];

            while (i <= j)
            {
                while (elements[i].CompareTo(pivot) < 0) i++;
                while (elements[j].CompareTo(pivot) > 0) j--;

                if (i <= j)
                {
                    // Swap
                    var tmp = elements[i];
                    elements[i] = elements[j];
                    elements[j] = tmp;

                    i++;
                    j--;
                }
            }

            List<Task> tasks = new List<Task>();
            // Recursive calls
            if (left < j) tasks.Add(Task.Run(() => TaskBasedQuicksort(elements, left, j)));
            if (i < right) tasks.Add(Task.Run(() => TaskBasedQuicksort(elements, i, right)));

            Task.WaitAll(tasks.ToArray());
        }

        public static void TaskBasedQuicksort2(long[] elements, long left, long right)
        {
            long i = left, j = right;
            var pivot = elements[(left + right) / 2];

            while (i <= j)
            {
                while (elements[i].CompareTo(pivot) < 0) i++;
                while (elements[j].CompareTo(pivot) > 0) j--;

                if (i <= j)
                {
                    // Swap
                    var tmp = elements[i];
                    elements[i] = elements[j];
                    elements[j] = tmp;

                    i++;
                    j--;
                }
            }

            List<Task> tasks = new List<Task>();
            // Recursive calls
            if (left < j) {
                if (j - left < 1000) tasks.Add(Task.Run(() => SerialQuicksort(elements, left, j))); 
                else tasks.Add(Task.Run(() => TaskBasedQuicksort2(elements, left, j)));
            }
            if (i < right) {
                if (right - i < 1000) tasks.Add(Task.Run(() => SerialQuicksort(elements, i, right))); 
                else tasks.Add(Task.Run(() => TaskBasedQuicksort2(elements, i, right)));
            }

            Task.WaitAll(tasks.ToArray());
        }
        
    }
}
