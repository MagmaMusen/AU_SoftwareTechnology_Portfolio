using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DoorLock
{
    class Program
    {
        static void Main(string[] args)
        {
            var doorLock = new LockMgr();

            doorLock.Green();
            doorLock.Red();
        }
    }
}
