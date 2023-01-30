    /////////////////////////////////////////////
    // Generate PublicKeys
    std::string message = "Tong Di Baca Moal Ngarti Maneh mah";
    std::string signature;

    ECDSA<ECP, SHA3_512>::Signer signer(privateKey);

    StringSource( message, true,
        new SignerFilter( prng, signer,
            new StringSink( signature )
        ) // SignerFilter
    ); // StringSource
    /////////////////////////////////////////////

    SHA3_512 nyumput;
    nyumput.Update((const byte*)Pesen.data(), Pesen.size());
    diglt.resize(nyumput.DigestSize() / 2);
	  nyumput.TruncatedFinal((byte*)&diglt[0], diglt.size());

    StringSource(Pesen, true, new HashFilter(nyumput, new StringSink(diglt)));

	  std::cout << "Pesan : " << Pesen << std::endl;
	  std::cout << "Digit : ";
	  StringSource(diglt, true, new Redirector(encoder));
    std::cout << std::endl;
