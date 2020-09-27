using System;

namespace GameOfLife
{
    abstract class GameOfLife
    {
        protected readonly int GridSize;
        private const int AliveThreshold = 25;
        protected int[,] CurGrid;
        protected int[,] NewGrid;

        public GameOfLife(int gridSize)
        {
            GridSize = gridSize;
            CurGrid = new int[GridSize, GridSize];
            NewGrid = new int[GridSize, GridSize];

            var rnd = new Random();
            for (var row = 0; row < GridSize; row++)
            {
                for (var col = 0; col < GridSize; col++)
                {
                    CurGrid[row, col] = (rnd.Next(100) < AliveThreshold) ? 1 : 0;
                }
            }
        }


        protected bool ShallLocationBeAlive(int row, int col)
        {
            var liveNeighbors = CalcAliveNeighbors(row, col);

            if (CurGrid[row, col] == 1)
            {
                if ((liveNeighbors == 2) || (liveNeighbors == 3))
                    return true;    // Alive and with two or three neighbors - live on
            }
            else if (liveNeighbors == 3)
            {
                return true; // Dead and with exactly three neighbors - live
            }
            return false;   // Die
        }

        protected int CalcAliveNeighbors(int row, int col)
        {
            int liveNeighbors;

            // Implementation of SequentialGameOfLife-rules
            if (row == 0)   // Top row
            {
                if (col == 0)    // Top left-hand corner
                    liveNeighbors = CurGrid[row, col + 1] +
                                       CurGrid[row + 1, col] + CurGrid[row + 1, col + 1];

                else if (col == GridSize - 1) // Top right-hand corner
                    liveNeighbors = CurGrid[row, col - 1] +
                                       CurGrid[row + 1, col - 1] + CurGrid[row + 1, col];

                else // On top edge
                    liveNeighbors = CurGrid[row, col - 1] + CurGrid[row, col + 1] +
                                       CurGrid[row + 1, col - 1] + CurGrid[row + 1, col] + CurGrid[row + 1, col + 1];
            }
            else if (row == GridSize - 1) // Bottom row
            {
                if (col == 0) // Bottom left-hand corner
                    liveNeighbors = CurGrid[row - 1, col] + CurGrid[row - 1, col + 1] +
                                                                   CurGrid[row, col + 1];

                else if (col == GridSize - 1) // Bottom right-hand corner
                    liveNeighbors = CurGrid[row - 1, col - 1] + CurGrid[row - 1, col] +
                                       CurGrid[row, col - 1];

                else // On bottom edge
                    liveNeighbors = CurGrid[row - 1, col - 1] + CurGrid[row - 1, col] + CurGrid[row - 1, col + 1] +
                                    CurGrid[row, col - 1] + CurGrid[row, col + 1];
            }
            else if (col == 0)
            {
                // Must be left edge, since corners are covered above
                liveNeighbors = CurGrid[row - 1, col] + CurGrid[row - 1, col + 1] +
                                                            CurGrid[row, col + 1] +
                                CurGrid[row + 1, col] + CurGrid[row + 1, col + 1];
            }
            else if (col == GridSize - 1)
            {
                // Must be right edge, since corners are covered above
                liveNeighbors = CurGrid[row - 1, col - 1] + CurGrid[row - 1, col] +
                                  CurGrid[row, col - 1] +
                                  CurGrid[row + 1, col - 1] + CurGrid[row + 1, col];

            }
            else
            {
                // Interior field
                liveNeighbors = CurGrid[row - 1, col - 1] + CurGrid[row - 1, col] + CurGrid[row, col + 1] +
                                    CurGrid[row + 1, col - 1] + CurGrid[row + 1, col] +
                                    CurGrid[row + 1, col - 1] + CurGrid[row + 1, col] + CurGrid[row + 1, col + 1];
            }


            return liveNeighbors;
        }

        protected void Swap<T>(ref T a, ref T b)
        {
            var temp = a;
            a = b;
            b = temp;
        }


        public abstract void Run(int steps);

    }
}