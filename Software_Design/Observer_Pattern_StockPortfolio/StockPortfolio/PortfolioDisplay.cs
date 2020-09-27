using System;
using System.Collections.ObjectModel;

namespace StockPortfolio
{
    class PortfolioDisplay : IObserver<Portfolio>
    {
        public void Update(Portfolio subject)
        {
            Console.Clear();
            Console.WriteLine("-------------------------------------------------------");
            Console.WriteLine("Stock portfolio:");
            ReadOnlyCollection<PortfolioEntry> entries = subject.GetPortfolioEntries();
            foreach (PortfolioEntry entry in entries)
            {
                Console.WriteLine("Stock: {0} - amount: {1} - price: {2} - held value: {3}", entry.stock.Name, entry.amount, entry.stock.Value, entry.stock.Value * entry.amount);
            }
            Console.WriteLine("Total holdings: {0}", subject.GetTotalStockValue());
        }
    }
}
