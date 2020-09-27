using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DoorLock
{
    public interface IState
    {
        void HdlRed(LockMgr lockMgr);
        void HdlGreen(LockMgr lockMgr);
    }
}
