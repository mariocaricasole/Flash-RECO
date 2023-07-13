#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "HepMCG4AsciiReaderMessenger.hh"
#include "HepMCG4AsciiReader.hh"



HepMCG4AsciiReaderMessenger::HepMCG4AsciiReaderMessenger(HepMCG4AsciiReader* agen) : gen(agen)
{
    dir= new G4UIdirectory("/generator/hepmcAscii/");
    dir-> SetGuidance("Reading HepMC event from an Ascii file");

    verbose = new G4UIcmdWithAnInteger("/generator/hepmcAscii/verbose", this);
    verbose-> SetGuidance("Set verbose level");
    verbose-> SetParameterName("verboseLevel", false, false);
    verbose-> SetRange("verboseLevel>=0 && verboseLevel<=1");

    open = new G4UIcmdWithAString("/generator/hepmcAscii/open", this);
    open-> SetGuidance("(re)open data file (HepMC Ascii format)");
    open-> SetParameterName("input ascii file", true, true);
}


HepMCG4AsciiReaderMessenger::~HepMCG4AsciiReaderMessenger()
{
    delete verbose;
    delete open;

    delete dir;
}


void HepMCG4AsciiReaderMessenger::SetNewValue(G4UIcommand* command, G4String newValues)
{
    if (command==verbose)
    {
        int level= verbose-> GetNewIntValue(newValues);
        gen-> SetVerboseLevel(level);
    }
    else if (command==open)
    {
        gen-> SetFileName(newValues);
        G4cout << "HepMC Ascii inputfile: " << gen-> GetFileName() << G4endl;
        gen-> Initialize();
    }
}



G4String HepMCG4AsciiReaderMessenger::GetCurrentValue(G4UIcommand* command)
{
    G4String cv;

    if (command == verbose)
        cv= verbose-> ConvertToString(gen-> GetVerboseLevel());
    else  if (command == open)
        cv= gen-> GetFileName();

    return cv;
}
