using System.Collections.Generic;

namespace StockPortfolio
{
    public abstract class Subject<T>
    {
        protected readonly List<IObserver<T>> observers = new List<IObserver<T>>();
        public void Attach(IObserver<T> observer)
        {
            observers.Add(observer);
        }

        public void Detach(IObserver<T> observer)
        {
            observers.Remove(observer);
        }
        

    }
}
