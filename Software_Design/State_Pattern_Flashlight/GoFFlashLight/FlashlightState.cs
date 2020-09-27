//============================================================
// AUTHOR:  TFJ
//============================================================

namespace GoFFlashlight
{
    public enum BeamIntensity {Low, High}
    public enum Color { White, Red, Green }


    public interface IFlashlightState
    {
        void OnEnter(IFlashlightBehavior lightBehavior);
        void OnExit(IFlashlightBehavior lightBehavior);
        void HandlePower(IFlashlightBehavior lightBehavior);
        void HandleMode(IFlashlightBehavior lightBehavior);
        void HandleColor(IFlashlightBehavior lightBehavior);
    }


    abstract class FlashlightState : IFlashlightState
    {
        public virtual void OnEnter(IFlashlightBehavior lightBehavior) { }
        public virtual void OnExit(IFlashlightBehavior lightBehavior) { }

        public virtual void HandlePower(IFlashlightBehavior lightBehavior){}
        public virtual void HandleMode(IFlashlightBehavior lightBehavior){}
        public virtual void HandleColor(IFlashlightBehavior lightBehavior){}
    }

    class PowerOffState : FlashlightState
    {
        private static PowerOffState _instance;
        static public PowerOffState Instance
        {
            get { return _instance ?? (_instance = new PowerOffState()); }
        }

        public override void OnEnter(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.TurnLightOff();
        }


        public override void HandlePower(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.State = PowerOnState.Instance;
        }
    }

    class PowerOnState : FlashlightState
    {
        private static PowerOnState _instance;
        static public PowerOnState Instance
        {
            get { return _instance ?? (_instance = new PowerOnState()); }
        }

        public override void OnEnter(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.TurnLightOn();
            lightBehavior.ColorState = WhiteLightColorState.Instance;
            lightBehavior.State = LowPowerState.Instance;
        }


        public override void HandlePower(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.State.OnExit(lightBehavior);
            lightBehavior.ColorState.OnExit(lightBehavior);
            lightBehavior.State = PowerOffState.Instance;
        }

        public override void HandleColor(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.ColorState.HandleColor(lightBehavior);
        }
    }

    class LowPowerState : PowerOnState
    {
        private static LowPowerState _instance;
        new static public LowPowerState Instance
        {
            get { return _instance ?? (_instance = new LowPowerState()); }
        }

        public override void OnEnter(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.SetBeamIntensity(BeamIntensity.Low);
        }

        public override void HandleMode(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.State = HighPowerState.Instance;
        }
    }

    class HighPowerState : PowerOnState
    {
        private static HighPowerState _instance;
        new static public HighPowerState Instance
        {
            get { return _instance ?? (_instance = new HighPowerState()); }
        }

        public override void OnEnter(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.SetBeamIntensity(BeamIntensity.High);
        }
        
        public override void HandleMode(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.State = LowPowerState.Instance;
        }
    }
}