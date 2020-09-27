namespace GoFFlashlight
{
    public interface IFlashlightColorState
    {
        void OnEnter(IFlashlightBehavior lightBehavior);
        void OnExit(IFlashlightBehavior lightBehavior);
        void HandleColor(IFlashlightBehavior lightBehavior);
    }


    class FlashlightColorState : IFlashlightColorState
    {
        public virtual void OnEnter(IFlashlightBehavior lightBehavior) { }
        public virtual void OnExit(IFlashlightBehavior lightBehavior) { }
        public virtual void HandleColor(IFlashlightBehavior lightBehavior) { }
    }

    class WhiteLightColorState : FlashlightColorState
    {
        private static WhiteLightColorState _instance;

        public static WhiteLightColorState Instance
        {
            get { return _instance ?? (_instance = new WhiteLightColorState()); }
        }

        public override void OnEnter(IFlashlightBehavior lightBehavior)
        {
            base.OnEnter(lightBehavior);
            lightBehavior.SetBeamColor(Color.White);
        }

        public override void HandleColor(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.ColorState = RedLightColorState.Instance;
        }

    }

    class RedLightColorState : FlashlightColorState
    {
        private static RedLightColorState _instance;
        static public RedLightColorState Instance
        {
            get { return _instance ?? (_instance = new RedLightColorState()); }
        }

        public override void OnEnter(IFlashlightBehavior lightBehavior)
        {
            base.OnEnter(lightBehavior);
            lightBehavior.SetBeamColor(Color.Red);
        }


        public override void HandleColor(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.ColorState = GreenLightColorState.Instance;
        }

    }

    class GreenLightColorState : FlashlightColorState
    {
        private static GreenLightColorState _instance;
        static public GreenLightColorState Instance
        {
            get { return _instance ?? (_instance = new GreenLightColorState()); }
        }


        public override void OnEnter(IFlashlightBehavior lightBehavior)
        {
            base.OnEnter(lightBehavior);
            lightBehavior.SetBeamColor(Color.Green);
        }


        public override void HandleColor(IFlashlightBehavior lightBehavior)
        {
            lightBehavior.ColorState = WhiteLightColorState.Instance;
        }
    }
}