#include "MuonSD.hh"

//constructor
MuonSD::MuonSD(G4String name) : G4VSensitiveDetector(name), fMuonCollection(NULL), fPositionResolution(5*cm)
{
    G4String HCname;
    collectionName.insert(HCname="muonCollection");
}


//destructor
MuonSD::~MuonSD()
{}


void MuonSD::Initialize(G4HCofThisEvent*HCE)
{
    static int HCID = -1;

    //make a new muon hits collection object
    fMuonCollection = new MuonHitsCollection(SensitiveDetectorName,collectionName[0]);

    //if no hit collection id is found, get it
    if(HCID<0)
        HCID = GetCollectionID(0);

    //add muon hits collection to the hits collection of this event
    HCE->AddHitsCollection(HCID,fMuonCollection);
}


G4bool MuonSD::ProcessHits(G4Step*aStep,G4TouchableHistory*)
{
    //get the energy deposited in the step
    G4double edep = aStep->GetTotalEnergyDeposit();

    //if the energy is zero, no need to proceed
    if(edep==0.)
        return true;

    //get the number of hits and the hit position
    MuonHit* aHit;
    int nHit = fMuonCollection->entries();
    G4ThreeVector hitpos = aStep->GetPreStepPoint()->GetPosition();

    //run over each hit...
    for(int i=0;i<nHit;i++)
    {
        //get hit and its position
        aHit = (*fMuonCollection)[i];
        G4ThreeVector pos = aHit->GetPos();
        //calculate distance between the step position and the hit
        G4double dist2 = sqr(pos.x()-hitpos.x())+sqr(pos.y()-hitpos.y())+sqr(pos.z()-hitpos.z());
        //if the distance is less than the position resolution, add the energy deposited in the hit
        if(dist2<=sqr(fPositionResolution))
            aHit->AddEdep(edep);
            return true;
    }

    //create new hit object and only pass the energy deposited and the pre-step point as position
    aHit = new MuonHit();
    aHit->SetEdep( edep );
    aHit->SetPos( aStep->GetPreStepPoint()->GetPosition() );
    fMuonCollection->insert( aHit );

    return true;
}


void MuonSD::EndOfEvent(G4HCofThisEvent*)
{}


void MuonSD::clear()
{}


void MuonSD::DrawAll()
{}


void MuonSD::PrintAll()
{}
