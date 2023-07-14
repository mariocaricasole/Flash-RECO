#ifndef HEPMC_G4_ASCII_READER_HH
#define HEPMC_G4_ASCII_READER_HH

#include "HepMCG4Interface.hh"
#include "HepMCG4AsciiReaderMessenger.hh"

#include "HepMC3/ReaderAscii.h"

#include <iostream>
#include <fstream>

class HepMCG4AsciiReader : public HepMCG4Interface
{
public:
    HepMCG4AsciiReader();
    ~HepMCG4AsciiReader();
    
    //(re)initialize ascii reader
    void Initialize();

    //getter and setter of file name
    inline G4String GetFileName() {return fileName; }
    inline void SetFileName(G4String name) {fileName = name; }

private:
    G4String fileName;

    //ascii reader from HepMC3 and custom UI messenger to change file name
    HepMC3::ReaderAscii *asciiInput;
    HepMCG4AsciiReaderMessenger *messenger;

    //generate HepMC3 event
    virtual HepMC3::GenEvent* GenerateHepMC3Event();
};
#endif
