#include "G4UIcommand.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithABool.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIdirectory.hh"
#include "G4UIparameter.hh"
#include "PrimaryGeneratorMessenger.hh"
#include "PrimaryGeneratorAction.hh"


PrimaryGeneratorMessenger::PrimaryGeneratorMessenger(PrimaryGeneratorAction* genaction) : fPrimaryAction(genaction)
{
    fMyDetDir = new G4UIdirectory("/mydet/");
    fMyDetDir-> SetGuidance(" detector control commands.");

    fDir= new G4UIdirectory("/generator/");
    fDir-> SetGuidance("Control commands for primary generator");

    fSelect= new G4UIcmdWithAString("/generator/select", this);
    fSelect-> SetGuidance("fSelect generator type");
    fSelect-> SetParameterName("generator_type", false, false);
    fSelect-> SetCandidates("particleGun pythia hepmcAscii");
    fSelect-> SetDefaultValue("particleGun");
}


PrimaryGeneratorMessenger::~PrimaryGeneratorMessenger()
{
    delete fSelect;
    delete fMyDetDir;
    delete fDir;
}


void PrimaryGeneratorMessenger::SetNewValue(G4UIcommand* command, G4String newValues)
{
    if ( command == fSelect ) {
        fPrimaryAction-> SetGenerator(newValues);
        G4cout << "current generator type: " << fPrimaryAction-> GetGeneratorName() << G4endl;
    }
}



G4String PrimaryGeneratorMessenger::GetCurrentValue(G4UIcommand* command)
{
    G4String cv, st;
    if ( command == fSelect )
        cv = fPrimaryAction-> GetGeneratorName();

    return cv;
}
