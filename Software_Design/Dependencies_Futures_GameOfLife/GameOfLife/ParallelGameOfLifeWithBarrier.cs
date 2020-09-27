using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace GameOfLife
{
    class ParallelGameOfLifeWithBarrier : GameOfLife
    {
        public ParallelGameOfLifeWithBarrier(int gridSize) : base(gridSize)
        {
        }

        public override void Run(int steps)
        {
            int nTasks = Environment.ProcessorCount;
            var stepBarrier = new Barrier(nTasks, _ => Swap(ref CurGrid, ref NewGrid));
            var tasks = new Task[nTasks];

            int chunkSize = GridSize/nTasks;

            for (int i = 0; i < nTasks; i++)
            {
                int rowStart = chunkSize*i;
                int rowEnd = (i == nTasks - 1) ? GridSize : rowStart + chunkSize;

                tasks[i] = Task.Run(() =>
                {
                    for (int s = 0; s < steps; s++)
                    {
                        for (var row = rowStart; row < rowEnd; row++)
                        {
                            for (var col = 0; col < GridSize; col++)
                            {
                                if (ShallLocationBeAlive(row, col))
                                {
                                    NewGrid[row, col] = 1;
                                }
                                else
                                {
                                    NewGrid[row, col] = 0;
                                }
                            }
                        }
                        stepBarrier.SignalAndWait();
                    }
                });
            }
            Task.WaitAll(tasks);
        }
    }
}
