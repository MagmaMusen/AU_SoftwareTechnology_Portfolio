using System;
using System.Collections.Generic;
using System.Text;

namespace StockPortfolio
{
    class Stock : Subject<Stock>
    {
        private int value;
        private string name;

        public Stock(int value, string name)
        {
            this.value = value;
            this.name = name;
        }

        public int Value
        {
            get => value;
            set
            {
                this.value = value;
                Notify();
            }
        }

        public string Name
        {
            get => name;
            private set => this.name = value;
        }

        public void Notify()
        {
            foreach (IObserver<Stock> observer in observers)
            {
                observer.Update(this);
            }
        }

        public void UpdateValue()
        {
            Random rand = new Random();
            int newPercentage = rand.Next(95, 106);
            int newValue = (Value * newPercentage) / 100;
            Value = newValue;
        }
    }
}
