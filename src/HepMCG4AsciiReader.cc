#include "HepMCG4AsciiReader.hh"
#include "HepMCG4AsciiReaderMessenger.hh"

HepMCG4AsciiReader::HepMCG4AsciiReader()
{
    //define new HepMC3 ascii reader and UI messenger
    asciiInput = new HepMC3::ReaderAscii(fileName);
    messenger = new HepMCG4AsciiReaderMessenger(this);
}


HepMCG4AsciiReader::~HepMCG4AsciiReader()
{
    delete asciiInput;
    delete messenger;
}


//delete old HepMC3 ascii reader and create a new one with the current filename
void HepMCG4AsciiReader::Initialize()
{
    delete asciiInput;
    asciiInput = new HepMC3::ReaderAscii(fileName);
}


//generate new HepMC3Event from the file, reading the next event (if present)
HepMC3::GenEvent *HepMCG4AsciiReader::GenerateHepMC3Event()
{
    HepMC3::GenEvent *evt = new HepMC3::GenEvent();
    asciiInput->read_event((*evt));
    if(!(evt))    return 0;

    return evt;
}
