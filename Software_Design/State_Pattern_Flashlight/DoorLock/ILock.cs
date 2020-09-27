namespace DoorLock
{
    interface ILock
    {
        void Disengage();
        void Engage();
    }

    class Lock : ILock
    {
        public void Disengage()
        {
            System.Console.WriteLine("Door is UNLOCKED");
        }

        public void Engage()
        {
            System.Console.WriteLine("Door is LOCKED");
        }
    }
}