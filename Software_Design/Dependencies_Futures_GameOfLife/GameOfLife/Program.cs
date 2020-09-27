using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameOfLife
{
    class Program
    {
        const int GridSize = 5000;
        static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
            GameOfLife gol;

            gol = new SequentialGameOfLife(GridSize);
            stopwatch.Start();
            gol.Run(100);
            stopwatch.Stop();
            Console.WriteLine("Sequential: " + stopwatch.ElapsedMilliseconds);

            gol = new ParallelGameOfLife(GridSize);
            stopwatch.Restart();
            gol.Run(100);
            stopwatch.Stop();
            Console.WriteLine("Parallel: " + stopwatch.ElapsedMilliseconds);

            gol = new ParallelGameOfLifeWithBarrier(GridSize);
            stopwatch.Restart();
            gol.Run(100);
            stopwatch.Stop();
            Console.WriteLine("Parallel with barrier: " + stopwatch.ElapsedMilliseconds);

        }
    }
}
