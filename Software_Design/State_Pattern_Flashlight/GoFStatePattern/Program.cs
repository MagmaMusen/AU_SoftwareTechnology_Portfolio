using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace TelephoneSystem
{
    class Program
    {
        static void Main(string[] args)
        {
            var phone = new Telephone();

            System.Console.WriteLine("*** TEST START ***");
            // Dial a number
            phone.DigitPressed(2);
            phone.DigitPressed(3);
            phone.DigitPressed(9);
            phone.DigitPressed(6);
            phone.DigitPressed(3);
            phone.DigitPressed(4);
            phone.DigitPressed(9);
            phone.DigitPressed(5);

            // Attempt connection
            phone.CallButtonPressed();

            // Wait a bit
            Thread.Sleep(1000);

            // Connect
            phone.ConnectionEstablished();

            // Wait a bit
            Thread.Sleep(2000);

            // Actively disconnect
            phone.CallButtonPressed();

            // Wait a bit
            Thread.Sleep(2000);

            phone.ConnectionLost();

            // Wait a bit
            Thread.Sleep(2000);
            System.Console.WriteLine("*** TEST COMPLETE ***");

        }
    }
}
