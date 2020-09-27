namespace DoorLock
{
    class State : IState
    {
        public virtual void HdlRed(LockMgr lockMgr)
        {
            
        }

        public virtual void HdlGreen(LockMgr lockMgr)
        {
            
        }
    }

    class Locked : State
    {
        public override void HdlGreen(LockMgr lockMgr)
        {
            lockMgr.Unlock();
            lockMgr.SetState(new Unlocked());
        }
    }

    class Unlocked : State
    {
        public override void HdlRed(LockMgr lockMgr)
        {
            lockMgr.Lock();
            lockMgr.SetState(new Locked());
        }

    }

}