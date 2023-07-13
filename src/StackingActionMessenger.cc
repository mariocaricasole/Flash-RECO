#include "StackingActionMessenger.hh"
#include "StackingAction.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4ios.hh"


StackingActionMessenger::StackingActionMessenger(StackingAction * msa) : G4UImessenger(), fMyAction(msa)
{
    fMuonCmd = new G4UIcmdWithAnInteger("/mydet/reqmuon",this);
    fMuonCmd->SetGuidance("Number of muon for the trigger.");
    fMuonCmd->SetParameterName("N",true);
    fMuonCmd->SetDefaultValue(2);
    fMuonCmd->SetRange("N>=0");

    fIsoMuonCmd = new G4UIcmdWithAnInteger("/mydet/isomuon",this);
    fIsoMuonCmd->SetGuidance("Number of isolated muon for the trigger.");
    fIsoMuonCmd->SetParameterName("N",true);
    fIsoMuonCmd->SetDefaultValue(2);
    fIsoMuonCmd->SetRange("N>=0");

    fIsoCmd = new G4UIcmdWithAnInteger("/mydet/isolation",this);
    fIsoCmd->SetGuidance("Maximum allowed number of hits in tracker");
    fIsoCmd->SetGuidance(" for an isolated muon track (includes hits by muon)");
    fIsoCmd->SetParameterName("N",true);
    fIsoCmd->SetDefaultValue(10);
    fIsoCmd->SetRange("N>=0");

    fRoiCmd = new G4UIcmdWithADoubleAndUnit("/mydet/RoIangle",this);
    fRoiCmd->SetGuidance("Define RoI angle");
    fRoiCmd->SetParameterName("theta",true,true);
    fRoiCmd->SetDefaultUnit("deg");
}


StackingActionMessenger::~StackingActionMessenger()
{
    delete fMuonCmd;
    delete fIsoMuonCmd;
    delete fIsoCmd;
    delete fRoiCmd;
}


void StackingActionMessenger::SetNewValue(G4UIcommand * command,G4String newValue)
{
    if(command==fMuonCmd)
        fMyAction->SetNRequestMuon(fMuonCmd->GetNewIntValue(newValue));
    else if(command==fIsoMuonCmd)
        fMyAction->SetNRequestIsoMuon(fIsoMuonCmd->GetNewIntValue(newValue));
    else if(command==fIsoCmd)
        fMyAction->SetNIsolation(fIsoCmd->GetNewIntValue(newValue));
    else if(command==fRoiCmd)
        fMyAction->SetRoIAngle(fRoiCmd->GetNewDoubleValue(newValue));
}


G4String StackingActionMessenger::GetCurrentValue(G4UIcommand * command)
{
    G4String cv;

    if(command==fMuonCmd)
        cv = fMuonCmd->ConvertToString(fMyAction->GetNRequestMuon());
    else if(command==fIsoMuonCmd)
        cv = fIsoMuonCmd->ConvertToString(fMyAction->GetNRequestIsoMuon());
    else if(command==fIsoCmd)
        cv = fIsoCmd->ConvertToString(fMyAction->GetNIsolation());
    else if(command==fRoiCmd)
        cv = fRoiCmd->ConvertToString(fMyAction->GetRoIAngle(),"deg");

    return cv;
}
