#include "TrackerSD.hh"
#include "TrackerHit.hh"
#include "G4Step.hh"
#include "G4HCofThisEvent.hh"
#include "G4TouchableHistory.hh"


TrackerSD::TrackerSD(G4String name) : G4VSensitiveDetector(name)
{
    G4String HCname;
    collectionName.insert(HCname="trackerCollection");
}


TrackerSD::~TrackerSD()
{}


void TrackerSD::Initialize(G4HCofThisEvent* HCE)
{
    static int HCID = -1;
    fTrackerCollection = new TrackerHitsCollection(SensitiveDetectorName,collectionName[0]);
    if(HCID<0)
        HCID = GetCollectionID(0);
    HCE->AddHitsCollection(HCID,fTrackerCollection);
}


G4bool TrackerSD::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{
    G4double edep = aStep->GetTotalEnergyDeposit();
    if(edep==0.)
        return false;

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
