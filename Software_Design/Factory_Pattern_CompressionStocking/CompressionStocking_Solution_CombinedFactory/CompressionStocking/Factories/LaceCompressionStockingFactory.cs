using CompressionStocking.BusinessLogic;
using CompressionStocking.Devices.Compression;
using CompressionStocking.Devices.UserInterface;
using CompressionStocking.Mechanisms.Compression;
using CompressionStocking.Mechanisms.UserInterface;

namespace CompressionStocking.Factories
{
    public class LaceCompressionStockingFactory : ICompressionStockingFactory
    {
        public ICompressionMechanism CreateComressionMechanism(ICompressionEventListener listener)
        {
            var mechanism = new LaceCompressionMechanism(40, 100, new LaceTighteningDevice());
            mechanism.CompressionEventListener = listener;

            return mechanism;
        }

        public IUserOutput CreateUserOutput()
        {
            return new UserOutput(new LED(), new LED(), new Vibrator());
        }

    }
}
