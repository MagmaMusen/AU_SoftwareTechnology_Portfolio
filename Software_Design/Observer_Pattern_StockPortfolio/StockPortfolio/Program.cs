using System;
using System.Threading;

namespace StockPortfolio
{
    class Program
    {
        static void Main(string[] args)
        {
            Portfolio portfolio = new Portfolio();
            PortfolioDisplay portfolioDisplay = new PortfolioDisplay();
            portfolio.Attach(portfolioDisplay);

            Stock google = new Stock(100, "Google");
            Stock vestas = new Stock(500, "Vestas");
            Stock softbank = new Stock(220, "Softbank");

            portfolio.Add(google, 10);
            portfolio.Add(vestas, 50);
            portfolio.Add(softbank, 200);

            for (int i = 0; i < 10; i++)
            {
                google.UpdateValue();
                vestas.UpdateValue();
                softbank.UpdateValue();
                Thread.Sleep(2000);
            }

            Console.WriteLine("");
            Console.WriteLine("Press return key to exit");
            Console.ReadLine();
        }
    }
}
