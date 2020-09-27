using System;

namespace GoFFlashlight
{
    // An RGB LED, i.e. it can be used both as a light emitter and 
    // a color filter. Thus, it implements both interfaces.
    public class RGBLED : ILightEmitter, IColorFilter
    {
        public void TurnOn()
        {
            Console.SetCursorPosition(0, 3);
            Console.WriteLine("ON ");
        }

        public void TurnOff()
        {
            Console.SetCursorPosition(0, 3);
            Console.WriteLine("OFF");
        }

        public void SetIntensity(BeamIntensity beamIntensity)
        {
            Console.SetCursorPosition(10, 3);
            Console.WriteLine("{0}   ", beamIntensity);
        }

        public void SetColor(Color color)
        {
            Console.SetCursorPosition(20, 3);
            Console.WriteLine("{0}              ", color);
        }
    }
}
