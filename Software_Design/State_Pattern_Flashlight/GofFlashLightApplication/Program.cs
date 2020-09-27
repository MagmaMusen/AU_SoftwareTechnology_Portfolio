using System;
using GoFFlashlight;

namespace GofFlashLightApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            var colorLED = new RGBLED();
            IFlashlightUI flashlightUi = new Flashlight(colorLED, colorLED);
            Console.SetCursorPosition(0,1);
            Console.WriteLine("POWER     INT.      COLOR");
            Console.WriteLine("=========================");
            var cont = true;
            while (cont)
            {
                var key = Console.ReadKey(true);
                switch (key.KeyChar)
                {
                    case 'p':
                    case 'P':
                        flashlightUi.PowerButtonPushed();
                        break;

                    case 'c':
                    case 'C':
                        flashlightUi.ColorButtonPushed();
                        break;

                    case 'm':
                    case 'M':
                        flashlightUi.ModeButtonPushed();
                        break;

                    case 'q':
                    case 'Q':
                        cont = false;
                        break;
                }
            }
        }
    }

}
