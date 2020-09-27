using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DoorLock
{
    public class LockMgr
    {
        private IState _curState;
        private ILock _lock;

        public LockMgr()
        {
            this._curState = new Locked();
            this._lock = new Lock();
        }

        public void Red()
        {
            _curState.HdlRed(this);
        }

        public void Green()
        {
            _curState.HdlGreen(this);
        }

        public void SetState(IState s)
        {
            _curState = s;
        }

        public void Unlock()
        {
            _lock.Disengage();
        }

        public void Lock()
        {
            _lock.Engage();
        }
    }
}
