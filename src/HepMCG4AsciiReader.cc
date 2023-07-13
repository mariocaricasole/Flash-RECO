#include "HepMCG4AsciiReader.hh"
#include "HepMCG4AsciiReaderMessenger.hh"

#include <iostream>
#include <fstream>


HepMCG4AsciiReader::HepMCG4AsciiReader() :  filename("xxx.dat"), verbose(0)
{
    asciiInput= new HepMC::IO_GenEvent(filename.c_str(), std::ios::in);

    messenger= new HepMCG4AsciiReaderMessenger(this);
}


HepMCG4AsciiReader::~HepMCG4AsciiReader()
{
    delete asciiInput;
    delete messenger;
}


void HepMCG4AsciiReader::Initialize()
{
    delete asciiInput;

    asciiInput= new HepMC::IO_GenEvent(filename.c_str(), std::ios::in);
}


HepMC::GenEvent* HepMCG4AsciiReader::GenerateHepMCEvent()
{
    HepMC::GenEvent* evt= asciiInput-> read_next_event();
    if(!evt)
        return 0; // no more event

    if(verbose>0)
        evt-> print();

    return evt;
}
