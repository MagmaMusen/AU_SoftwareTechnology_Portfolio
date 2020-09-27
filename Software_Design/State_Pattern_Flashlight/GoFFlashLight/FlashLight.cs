namespace GoFFlashlight
{
    public interface IFlashlightBehavior
    {
        void SetBeamIntensity(BeamIntensity beamIntensity);
        void SetBeamColor(Color color);
        void TurnLightOn();
        void TurnLightOff();

        IFlashlightColorState ColorState { get; set; }
        IFlashlightState State { get; set; }
    }

    public interface IFlashlightUI
    {
        void ColorButtonPushed();
        void PowerButtonPushed();
        void ModeButtonPushed();
    }

    public class Flashlight : IFlashlightBehavior, IFlashlightUI
    {
        private IFlashlightState _state;
        public IFlashlightState State
        {
            get { return _state; }
            set
            {
                _state = value;
                _state.OnEnter(this);
            }
        }
        
        private IFlashlightColorState _colorState;
        private readonly ILightEmitter _lightEmitter;
        private readonly IColorFilter _colorFilter;


        public IFlashlightColorState ColorState
        {
            get { return _colorState; }
            set
            {
                _colorState = value;
                _colorState.OnEnter(this);
            }
        }

        public Flashlight(ILightEmitter lightEmitter, IColorFilter colorFilter)
        {
            _state = PowerOffState.Instance;
            _colorState = WhiteLightColorState.Instance;
            _lightEmitter = lightEmitter;
            _colorFilter = colorFilter;

            _state.OnEnter(this);
            _colorState.OnEnter(this);
        }

        // UI event handlers (deletage events)
        public void ModeButtonPushed()
        {
            _state.HandleMode(this);
        }

        public void PowerButtonPushed()
        {
            _state.HandlePower(this);
        }

        public void ColorButtonPushed()
        {
            _state.HandleColor(this);
        }

        // Action handlers, called from state machine
        public void TurnLightOn()
        {
            _lightEmitter.TurnOn();
        }

        public void TurnLightOff()
        {
            _lightEmitter.TurnOff();
        }

        public void SetBeamIntensity(BeamIntensity beamIntensity)
        {
            _lightEmitter.SetIntensity(beamIntensity);
        }

        public void SetBeamColor(Color color)
        {
            _colorFilter.SetColor(color);
        }
    }

}