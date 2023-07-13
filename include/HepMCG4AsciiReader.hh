#ifndef HEPMC_G4_ASCII_READER_H
#define HEPMC_G4_ASCII_READER_H

#include "HepMCG4Interface.hh"
#include "HepMC/IO_GenEvent.h"

class HepMCG4AsciiReaderMessenger;

class HepMCG4AsciiReader : public HepMCG4Interface {
protected:
    G4String filename;
    HepMC::IO_GenEvent* asciiInput;

    G4int verbose;
    HepMCG4AsciiReaderMessenger* messenger;

    virtual HepMC::GenEvent* GenerateHepMCEvent();

public:
    HepMCG4AsciiReader();
    ~HepMCG4AsciiReader();

    // set/get methods
    void SetFileName(G4String name);
    G4String GetFileName() const;

    void SetVerboseLevel(G4int i);
    G4int GetVerboseLevel() const;

    // methods...
    void Initialize();
};

// ====================================================================
// inline functions
// ====================================================================

inline void HepMCG4AsciiReader::SetFileName(G4String name)
{
    filename= name;
}

inline G4String HepMCG4AsciiReader::GetFileName() const
{
    return filename;
}

inline void HepMCG4AsciiReader::SetVerboseLevel(G4int i)
{
    verbose= i;
}

inline G4int HepMCG4AsciiReader::GetVerboseLevel() const
{
    return verbose;
}

#endif
