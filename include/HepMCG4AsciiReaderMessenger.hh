#ifndef HEPMC_G4_ASCII_READER_MESSENGER_HH
#define HEPMC_G4_ASCII_READER_MESSENGER_HH

#include "G4UImessenger.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIdirectory.hh"

//dummy class to avoid warnings
class HepMCG4AsciiReader;


class HepMCG4AsciiReaderMessenger : public G4UImessenger
{
public:
    HepMCG4AsciiReaderMessenger(HepMCG4AsciiReader *fread);
    ~HepMCG4AsciiReaderMessenger();

    //setter and getter
    void SetNewValue(G4UIcommand *command, G4String newValues);
    G4String GetCurrentValue(G4UIcommand *command);

private:
    //customized ascii reader
    HepMCG4AsciiReader *fReader;

    //directory and "open" command
    G4UIdirectory *readerDir;
    G4UIcmdWithAString *open;
};

#endif
