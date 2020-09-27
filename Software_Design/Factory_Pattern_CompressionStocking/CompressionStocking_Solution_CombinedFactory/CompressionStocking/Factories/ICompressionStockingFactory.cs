using CompressionStocking.BusinessLogic;
using CompressionStocking.Mechanisms.Compression;
using CompressionStocking.Mechanisms.UserInterface;

namespace CompressionStocking.Factories
{
    public interface ICompressionStockingFactory
    {
        ICompressionMechanism CreateComressionMechanism(ICompressionEventListener listener);
        IUserOutput CreateUserOutput();
    }
}