namespace GoFFlashlight
{
    // ILightEmitter (e.g. a bulb, an LED, ...)
    public interface ILightEmitter
    {
        void TurnOn();
        void TurnOff();
        void SetIntensity(BeamIntensity beamIntensity);
    }

    // IColorFilter (e.g. colored glass, RGB LED, ...)
    public interface IColorFilter
    {

        void SetColor(Color color);
    }


}
