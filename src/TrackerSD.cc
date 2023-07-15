#include "TrackerSD.hh"

//constructor
TrackerSD::TrackerSD(G4String name) : G4VSensitiveDetector(name)
{
    G4String HCname;
    collectionName.insert(HCname="trackerCollection");
}


//destructor
TrackerSD::~TrackerSD()
{}


void TrackerSD::Initialize(G4HCofThisEvent* HCE)
{
    static int HCID = -1;

    //make a new tracker hit collection object
    fTrackerCollection = new TrackerHitsCollection(SensitiveDetectorName,collectionName[0]);

    //if no collection id is found, get it
    if(HCID<0)
        HCID = GetCollectionID(0);

    //add tracker hits collection to the hits collection of this event
    HCE->AddHitsCollection(HCID,fTrackerCollection);
}


G4bool TrackerSD::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{
    //get the energy deposited in the step
    G4double edep = aStep->GetTotalEnergyDeposit();

    //if the energy deposited is zero, no need to proceed
    if(edep==0.)
        return false;

    //create new hit object and pass the energy deposited and the pre-step point as position
    TrackerHit* newHit = new TrackerHit();
    newHit->SetEdep(edep);
    newHit->SetPos(aStep->GetPreStepPoint()->GetPosition());
    fTrackerCollection->insert(newHit);

    return true;
}


void TrackerSD::EndOfEvent(G4HCofThisEvent*)
{}


void TrackerSD::clear()
{}


void TrackerSD::DrawAll()
{}


void TrackerSD::PrintAll()
{}
