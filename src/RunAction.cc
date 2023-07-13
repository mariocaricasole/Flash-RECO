#include "G4Run.hh"
#include "G4RunManager.hh"
#include "RunAction.hh"


RunAction::RunAction() : G4UserRunAction()
{}


RunAction::~RunAction()
{}


void RunAction::BeginOfRunAction(const G4Run* aRun)
{
    G4cout << "### Run " << aRun-> GetRunID() << " start." << G4endl;
    G4RunManager::GetRunManager()-> SetRandomNumberStore(true);
}
