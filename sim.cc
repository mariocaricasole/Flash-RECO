#include "G4Types.hh"

#include "FTFP_BERT.hh"
#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"

#include "DetectorConstruction.hh"
#include "EventAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "StackingAction.hh"
#include "SteppingAction.hh"
#include "SteppingVerbose.hh"
#include "TrackingAction.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

int main(int argc,char** argv)
{

    // User Verbose output class
    G4VSteppingVerbose* verbosity = new SteppingVerbose;
    G4VSteppingVerbose::SetInstance(verbosity);

    // Serial only Run manager
    G4RunManager *runManager = new G4RunManager();

    // User Initialization classes (mandatory)
    G4VUserDetectorConstruction* detector = new DetectorConstruction;
    runManager->SetUserInitialization(detector);

    G4VUserPhysicsList* physics = new FTFP_BERT;
    runManager->SetUserInitialization(physics);

    runManager->Initialize();

    // User Action classes
    G4VUserPrimaryGeneratorAction* gen_action = new PrimaryGeneratorAction;
    runManager->SetUserAction(gen_action);

    /*G4UserRunAction* run_action = new RunAction;
    runManager->SetUserAction(run_action);

    G4UserEventAction* event_action = new EventAction;
    runManager->SetUserAction(event_action);

    G4UserStackingAction* stacking_action = new StackingAction;
    runManager->SetUserAction(stacking_action);

    G4UserTrackingAction* tracking_action = new TrackingAction;
    runManager->SetUserAction(tracking_action);

    G4UserSteppingAction* stepping_action = new SteppingAction;
    runManager->SetUserAction(stepping_action);
*/
    G4UIExecutive *ui = 0;

    if(argc==1)
    {
        ui = new G4UIExecutive(argc, argv);
    }

    //visualization manager
    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();

    //user interface manager
    G4UImanager *UImanager = G4UImanager::GetUIpointer();

    //if no argument is passed, use visualization mode, otherwise go to batch mode
    if(ui)
    {
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
    }
    else
    {
        G4String command = "/control/execute/ ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }

    // Free the store: user actions, physics_list and detector_description are
    //                 owned and deleted by the run manager, so they should not
    //                 be deleted in the main() program !

    delete visManager;
    delete runManager;
    delete verbosity;
}
