using System;
using CompressionStocking;
using CompressionStocking.BusinessLogic;
using CompressionStocking.Factories;

namespace CompressionStockingApplication
{
  class CompressionStockingApplication
    {
        static void Main(string[] args)
        {
            ConsoleKeyInfo consoleKeyInfo;
            ICompressionStockingFactory factory = null;

            Console.WriteLine("Compression Stocking Configuration");
            Console.WriteLine("A:   Air compression mechanism");
            Console.WriteLine("Z:   Laces compresison mechanism");
            Console.WriteLine("ESC: Terminate application");
            var configOk = false;

            do
            {
                consoleKeyInfo = Console.ReadKey(true); // true = do not echo character

                // Create the correct kind of factory
                if (consoleKeyInfo.Key == ConsoleKey.A)
                {
                    factory = new AirCompressionStockingFactory();
                    configOk = true;
                }
                if (consoleKeyInfo.Key == ConsoleKey.Z)
                {
                    factory = new LaceCompressionStockingFactory();
                    configOk = true;
                }
            } while (!configOk);

            // Create the Stocking Controller using the factory corresponding to user's choice
            var stockingCtrl = new StockingCtrl(factory);

            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine("Compression Stocking Control User Interface");
            Console.WriteLine("A:   Compress");
            Console.WriteLine("Z:   Decompress");
            Console.WriteLine("ESC: Terminate application");

            do
            {
                consoleKeyInfo = Console.ReadKey(true); // true = do not echo character
                if (consoleKeyInfo.Key == ConsoleKey.A)  stockingCtrl.StartBtnPushed();
                if (consoleKeyInfo.Key == ConsoleKey.Z)  stockingCtrl.StopBtnPushed();

            } while (consoleKeyInfo.Key != ConsoleKey.Escape);
        }
    }
}
