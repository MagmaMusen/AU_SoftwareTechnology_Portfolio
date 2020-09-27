using System;
using System.Diagnostics;

namespace QuickSort
{
    class Program
    {
        static void Main(string[] args)
        {
            const int numberOfElements = 20000000;
            DataGenerator dataGenerator = new DataGenerator();
            dataGenerator.Generate(numberOfElements);

            var stopwatch = new Stopwatch();

            for (int i = 0; i < 3; i++)
            {
                long[] numbers = dataGenerator.GetNumbers();

                Console.WriteLine("QuickSort By Recursive Method - run # {0}", i);
                stopwatch.Reset();
                stopwatch.Start();
                QuickSortSingleThread.SerialQuicksort(numbers, 0, numberOfElements - 1);
                stopwatch.Stop();

                var singleThreadRuntime = stopwatch.ElapsedMilliseconds;

                System.Console.WriteLine("Single thread calculation runtime: {0} ms", singleThreadRuntime);
            }
            
            System.Console.WriteLine("-----------------------------");
            for (int i = 0; i < 3; i++)
            {
                long[] numbers = dataGenerator.GetNumbers();

                Console.WriteLine("QuickSort By TaskBased Recursive Method - run # {0}", i);
                stopwatch.Reset();
                stopwatch.Start();
                QuickSortSingleThread.TaskBasedQuicksort(numbers, 0, numberOfElements - 1);
                stopwatch.Stop();

                var taskBasedThreadRuntime = stopwatch.ElapsedMilliseconds;

                System.Console.WriteLine("Task Based thread calculation runtime: {0} ms", taskBasedThreadRuntime);
            }

            System.Console.WriteLine("-----------------------------");
            for (int i = 0; i < 3; i++)
            {
                long[] numbers = dataGenerator.GetNumbers();

                Console.WriteLine("QuickSort By TaskBased2 Recursive Method - run # {0}", i);
                stopwatch.Reset();
                stopwatch.Start();
                QuickSortSingleThread.TaskBasedQuicksort2(numbers, 0, numberOfElements - 1);
                stopwatch.Stop();

                var taskBased2ThreadRuntime = stopwatch.ElapsedMilliseconds;

                System.Console.WriteLine("Task Based2 thread calculation runtime: {0} ms", taskBased2ThreadRuntime);
            }
        }
    }
}
