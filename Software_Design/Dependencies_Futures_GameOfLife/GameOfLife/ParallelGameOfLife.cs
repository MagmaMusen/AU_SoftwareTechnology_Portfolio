using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameOfLife
{
    class ParallelGameOfLife : GameOfLife
    {
        public ParallelGameOfLife(int gridSize) : base(gridSize)
        {
        }

        public override void Run(int steps)
        {
            for (int i = 0; i < steps; i++)
            {
                Parallel.For(0, GridSize, row =>
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
                );
                Swap(ref CurGrid, ref NewGrid);
            }
        }
    }
}
