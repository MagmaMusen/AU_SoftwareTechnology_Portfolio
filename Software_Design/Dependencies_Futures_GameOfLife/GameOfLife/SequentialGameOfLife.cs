using System;

namespace GameOfLife
{
    class SequentialGameOfLife : GameOfLife
    {


        public SequentialGameOfLife(int gridSize) : base(gridSize)
        {
        }


        public override void Run(int steps)
        {
            for (int i = 0; i < steps; i++)
            {
                for (var row = 0; row < GridSize; row++)
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
                Swap(ref CurGrid, ref NewGrid);
            }
        }


    }
}
