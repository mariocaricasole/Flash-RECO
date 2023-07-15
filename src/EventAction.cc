#include "EventAction.hh"

EventAction::EventAction() : G4UserEventAction(), ftrackerCollID(-1), fcalorimeterCollID(-1), fmuonCollID(-1)
{}


EventAction::~EventAction()
{}


void EventAction::BeginOfEventAction(const G4Event*)
{
    //if the sensitive detectors collection ID are not set, get them
    G4SDManager* SDman = G4SDManager::GetSDMpointer();
    if ( ftrackerCollID<0 || fcalorimeterCollID<0 || fmuonCollID<0)
    {
        G4String colNam;
        ftrackerCollID = SDman-> GetCollectionID(colNam="trackerCollection");
        fcalorimeterCollID = SDman-> GetCollectionID(colNam="calCollection");
        fmuonCollID = SDman-> GetCollectionID(colNam="muonCollection");
    }
}


void EventAction::EndOfEventAction(const G4Event* evt)
{
    G4cout << ">>> Event " << evt->GetEventID() << G4endl;

    //if no collection has been identified, don't proceed
    if( ftrackerCollID<0 || fcalorimeterCollID<0 || fmuonCollID<0)
        return;

    //get hit collection of this event and declare sub-collections for each detector
    G4HCofThisEvent* HCE = evt-> GetHCofThisEvent();
    TrackerHitsCollection* THC = NULL;
    CalorimeterHitsCollection* CHC = NULL;
    MuonHitsCollection* MHC = NULL;

    //if the hit collection is found, set each sub-collection according to the ID
    if(HCE)
    {
        THC = (TrackerHitsCollection*)(HCE->GetHC(ftrackerCollID));
        CHC = (CalorimeterHitsCollection*)(HCE->GetHC(fcalorimeterCollID));
        MHC = (MuonHitsCollection*)(HCE->GetHC(fmuonCollID));
    }

    //if tracker hit collection was found, show the number of hits
    if(THC)
    {
        G4int n_hit = THC-> entries();
        G4cout << "     " << n_hit << " hits are stored in TrackerHitsCollection." << G4endl;
    }

    //if the calorimeter hit collection was found, show the number of hits and the total energy deposited
    if(CHC)
    {
        G4int n_hit = CHC-> entries();
        G4cout << "     " << n_hit << " hits are stored in CalorimeterHitsCollection." << G4endl;
        G4double totE = 0;
        for( int i = 0; i < n_hit; i++ )
        {
            totE += (*CHC)[i]-> GetEdep();
        }
        G4cout << "     Total energy deposition in calorimeter : " << totE / GeV << " (GeV)" << G4endl;
    }

    //if the muon hit collection was found, show the number of hits
    if(MHC)
    {
        G4int n_hit = MHC-> entries();
        G4cout << "     " << n_hit << " hits are stored in MuonHitsCollection." << G4endl;
    }
}
