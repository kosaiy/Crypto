int main(int argc, char* argv[])
{
    AutoSeededRandomPool prng;

    AlgorithmParameters params = MakeParameters
        (Name::ModulusSize(), 2048)
        (Name::SubgroupOrderSize(), 256);

    DSA::PrivateKey privateKey;
    privateKey.GenerateRandom(prng, params);

    std::cout << "Test key: " << std::endl;
    HexEncoder hex(new FileSink(std::cout));
    privateKey.Save(hex);
    std::cout << std::endl;
}
