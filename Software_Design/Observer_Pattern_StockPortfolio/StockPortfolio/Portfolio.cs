using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Text;
using StockPortfolio;

namespace StockPortfolio
{
    class Portfolio : Subject<Portfolio>, IObserver<Stock>
    {
        private readonly List<PortfolioEntry> stockList = new List<PortfolioEntry>();

        public void Add(Stock stock, int amount)
        {
            stockList.Add(new PortfolioEntry() {amount = amount, stock = stock});
            stock.Attach(this);
            NotifyPortfolioChanged();
        }

        public void Update(Stock subject)
        {
            NotifyPortfolioChanged();
        }

        void NotifyPortfolioChanged()
        {
            foreach (IObserver<Portfolio> observer in observers)
            {
                observer.Update(this);
            }
        }

        public int GetTotalStockValue()
        {
            int totalValue = 0;
            foreach (PortfolioEntry entry in stockList)
            {
                int stockValue = entry.amount * entry.stock.Value;
                totalValue += stockValue;
            }
            return totalValue;
        }

        public ReadOnlyCollection<PortfolioEntry> GetPortfolioEntries()
        {
            return stockList.AsReadOnly();
        }
    }
}