using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TelephoneSystem
{
    // Interface to be used by GUI
    public interface IGuiEventHandler
    {
        void DigitPressed(uint digit);
        void CallButtonPressed();
    }

    // Interface to be used by states
    public interface IActionHandler
    {
        void AddDigit(uint digit);
        void CallNumber();
        void MakeBusyTone();
        void MakeInvalidNumberTone();
        void Silence();
        void Disconnect();
        void TurnMicrophoneOn();
        void TurnMicrophoneOff();
        void SetState(ITelephoneState newState);
    }


    // Interface to be used by telephone system
    public interface ITelephoneSystemHandler
    {
        void ConnectionEstablished();
        void ConnectionLost();
        void LineBusy();
        void InvalidNumber();
    }


    // The telephone class
    public class Telephone : IGuiEventHandler, IActionHandler, ITelephoneSystemHandler
    {
        private ITelephoneState _state;
        private uint _curNumber;

        public Telephone()
        {
            _state = new IdleState();
            _curNumber = 0;
        }

        
        // From IGuiEventHandler
        public void DigitPressed(uint digit)
        {
            _state.HandleDigitPressed(digit, this);
        }

        public void CallButtonPressed()
        {
            _state.HandleCallButtonPressed(this);
        }

        // From IActionHandler
        public void AddDigit(uint digit)
        {
            System.Console.WriteLine("Telephone: Adding digit {0}", digit);
            _curNumber = _curNumber*10 + digit;
        }

        public void CallNumber()
        {
            System.Console.WriteLine("Telephone: Calling number {0}", _curNumber);
        }

        public void MakeBusyTone()
        {
            System.Console.WriteLine("Telephone: Beep...beep...beep....");
        }

        public void MakeInvalidNumberTone()
        {
            System.Console.WriteLine("Telephone: Invalid number");
        }

        public void Silence()
        {
            System.Console.WriteLine("Telephone: (silence)");
        }

        public void Disconnect()
        {
            System.Console.WriteLine("Telephone: Disconnecting");
        }

        public void TurnMicrophoneOn()
        {
            System.Console.WriteLine("Telephone: Turning mike ON");
        }

        public void TurnMicrophoneOff()
        {
            System.Console.WriteLine("Telephone: Turning mike OFF");
        }

        public void SetState(ITelephoneState newState)
        {
            _state.OnExit(this);
            _state = newState;
            _state.OnEnter(this);
        }

        // From ITelephoneSystemHandler
        public void ConnectionEstablished()
        {
            _state.HandleConnectionEstablished(this);
        }

        public void ConnectionLost()
        {
            _state.HandleDisconnected(this);
        }

        public void LineBusy()
        {
            _state.HandleLineBusy(this);
        }

        public void InvalidNumber()
        {
            _state.HandleInvalidNumber(this);
        }
    }
}
