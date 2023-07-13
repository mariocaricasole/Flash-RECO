#include "G4HCofThisEvent.hh"
#include "G4ios.hh"
#include "G4Step.hh"
#include "G4SystemOfUnits.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "MuonSD.hh"
#include "MuonHit.hh"


MuonSD::MuonSD(G4String name) : G4VSensitiveDetector(name), fMuonCollection(NULL), fPositionResolution(5*cm)
{
    G4String HCname;
    collectionName.insert(HCname="muonCollection");
}


MuonSD::~MuonSD()
{}


void MuonSD::Initialize(G4HCofThisEvent*HCE)
{
    static int HCID = -1;
    fMuonCollection = new MuonHitsCollection
                    (SensitiveDetectorName,collectionName[0]);
    if(HCID<0)
        HCID = GetCollectionID(0);
    HCE->AddHitsCollection(HCID,fMuonCollection);
}


G4bool MuonSD::ProcessHits(G4Step*aStep,G4TouchableHistory*)
{
    G4double edep = aStep->GetTotalEnergyDeposit();

    if(edep==0.)
        return true;

    MuonHit* aHit;
    int nHit = fMuonCollection->entries();
    G4ThreeVector hitpos = aStep->GetPreStepPoint()->GetPosition();
    for(int i=0;i<nHit;i++)
    {
        aHit = (*fMuonCollection)[i];
        G4ThreeVector pos = aHit->GetPos();
        G4double dist2 = sqr(pos.x()-hitpos.x())+sqr(pos.y()-hitpos.y())+sqr(pos.z()-hitpos.z());
        if(dist2<=sqr(fPositionResolution))
            aHit->AddEdep(edep);
            return true;
    }

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
