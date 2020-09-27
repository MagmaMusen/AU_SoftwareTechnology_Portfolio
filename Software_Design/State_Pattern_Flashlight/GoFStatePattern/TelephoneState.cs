namespace TelephoneSystem
{
    // Interface for telephone states
    public interface ITelephoneState
    {
        // State events
        void OnEnter(IActionHandler handler);
        void OnExit(IActionHandler handler);

        // User events
        void HandleDigitPressed(uint digit, IActionHandler handler);
        void HandleCallButtonPressed(IActionHandler handler);

        // Telephone system events
        void HandleConnectionEstablished(IActionHandler handler);
        void HandleLineBusy(IActionHandler handler);
        void HandleInvalidNumber(IActionHandler handler);
        void HandleDisconnected(IActionHandler telephone);
    }


    // Base class for states - provides default implementations 
    // for all events
    public class TelephoneState : ITelephoneState
    {
        public virtual void OnEnter(IActionHandler handler) { }
        public virtual void OnExit(IActionHandler handler) { }
        public virtual void HandleDigitPressed(uint digit, IActionHandler handler) { }
        public virtual void HandleCallButtonPressed(IActionHandler handler) { }
        public virtual void HandleConnectionEstablished(IActionHandler handler) { }
        public virtual void HandleLineBusy(IActionHandler handler) { }
        public virtual void HandleInvalidNumber(IActionHandler handler) { }
        public virtual void HandleDisconnected(IActionHandler telephone) { }
    }



    // Idle state
    class IdleState : TelephoneState
    {
        public override void HandleDigitPressed(uint digit, IActionHandler handler)
        {
            handler.AddDigit(digit);
        }

        public override void HandleCallButtonPressed(IActionHandler handler)
        {
            handler.CallNumber();
            handler.SetState(new AwaitingConnectionState());
        }

    }

    class AwaitingConnectionState : TelephoneState
    {
        public override void HandleConnectionEstablished(IActionHandler handler)
        {
            handler.TurnMicrophoneOn();
            handler.SetState(new ConnectedState());
        }

        public override void HandleLineBusy(IActionHandler handler)
        {
            handler.MakeBusyTone();
            handler.SetState(new BusyState());
        }
        public override void HandleInvalidNumber(IActionHandler handler)
        {
            handler.MakeInvalidNumberTone();
            handler.SetState(new BusyState());
        }

    }

    class BusyState : TelephoneState
    {
        public override void HandleCallButtonPressed(IActionHandler handler)
        {
            handler.Silence();
            handler.SetState(new IdleState());
        }
    }

    class ConnectedState : TelephoneState
    {
        public override void HandleCallButtonPressed(IActionHandler handler)
        {
            handler.TurnMicrophoneOff();
            handler.Disconnect();
            handler.SetState(new AwaitDisconnectedState());
        }

        public override void HandleDisconnected(IActionHandler handler)
        {
            handler.SetState(new IdleState());
        }

    }

    class AwaitDisconnectedState : TelephoneState
    {
        public override void HandleDisconnected(IActionHandler handler)
        {
            handler.SetState(new IdleState());
        }
    }

}
