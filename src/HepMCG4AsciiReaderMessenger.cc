#include "HepMCG4AsciiReaderMessenger.hh"
#include "HepMCG4AsciiReader.hh"

HepMCG4AsciiReaderMessenger::HepMCG4AsciiReaderMessenger(HepMCG4AsciiReader *fread)
{
    //private member corresponds to the ascii reader
    fReader = fread;

    //define directory in UI
    readerDir = new G4UIdirectory("/asciiReader/");
    readerDir->SetGuidance("Reader of HepMC3 ascii files to feed the primary generator");

    //define "open" command to change the file name and open it
    open = new G4UIcmdWithAString("/asciiReader/open",this);
    open->SetGuidance("Open Ascii file and initialize into the reader");
    open->SetParameterName("fileName",true);
    open->SetDefaultValue("event0.dat");

    //file name is set to default
    fReader->SetFileName("event0.dat");
    //fReader->Initialize();
}


HepMCG4AsciiReaderMessenger::~HepMCG4AsciiReaderMessenger()
{
    delete fReader;
    delete readerDir;
    delete open;
}


void HepMCG4AsciiReaderMessenger::SetNewValue(G4UIcommand *command, G4String newValues)
{
    if(command == open)
        //instruct the reader to change the name of the file
        fReader->SetFileName(newValues);
}


G4String HepMCG4AsciiReaderMessenger::GetCurrentValue(G4UIcommand *command)
{
    G4String cv;

    if(command == open)
        //return the file name
        cv = fReader->GetFileName();
    else
        cv = "No valid command passed";

    return cv;
}
