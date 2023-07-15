#ifndef STACKING_ACTION_MESSENGER_HH
#define STACKING_ACTION_MESSENGER_HH

#include "G4UImessenger.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4ios.hh"
#include "globals.hh"

//dummy class to avoid warnings
class StackingAction;

class StackingActionMessenger: public G4UImessenger {
public:
    StackingActionMessenger(StackingAction* msa);
    ~StackingActionMessenger();

    virtual void SetNewValue(G4UIcommand * command,G4String newValues);
    virtual G4String GetCurrentValue(G4UIcommand * command);

private:
    StackingAction * fMyAction;

    G4UIcmdWithAnInteger * fMuonCmd;
    G4UIcmdWithAnInteger * fIsoMuonCmd;
    G4UIcmdWithAnInteger * fIsoCmd;
    G4UIcmdWithADoubleAndUnit * fRoiCmd;

};

#endif
