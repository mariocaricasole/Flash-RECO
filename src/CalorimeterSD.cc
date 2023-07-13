#include "G4ios.hh"
#include "G4LogicalVolume.hh"
#include "G4ParticleDefinition.hh"
#include "G4Step.hh"
#include "G4SystemOfUnits.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VTouchable.hh"
#include "CalorimeterSD.hh"
#include "CalorimeterHit.hh"


CalorimeterSD::CalorimeterSD(G4String name) : G4VSensitiveDetector(name), fCalCollection(NULL), fnumberOfCellsInZ(20), fnumberOfCellsInPhi(48)
{
    G4String HCname;
    collectionName.insert(HCname="calCollection");
}


CalorimeterSD::~CalorimeterSD()
{}


void CalorimeterSD::Initialize(G4HCofThisEvent*)
{
    fCalCollection = new CalorimeterHitsCollection(SensitiveDetectorName, collectionName[0]);

    for ( G4int j = 0; j < fnumberOfCellsInZ; j++)
    {
        for(G4int k = 0; k < fnumberOfCellsInPhi; k++)
        {
            fCellID[j][k] = -1;
        }
    }

    verboseLevel = 0;
}


G4bool CalorimeterSD::ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist)
{
    if ( !ROhist )
        return false;

    G4double edep = aStep-> GetTotalEnergyDeposit();

    if ( verboseLevel > 1 )
        G4cout << "Next step edep(MeV) = " << edep/MeV << G4endl;

    if ( edep == 0. )
        return false;

    G4VPhysicalVolume* physVol = ROhist-> GetVolume();
    //ROhist->MoveUpHistory();
    //G4VPhysicalVolume* mothVol = ROhist->GetVolume(1);
    G4int copyIDinZ = ROhist-> GetReplicaNumber();
    G4int copyIDinPhi = ROhist-> GetReplicaNumber(1);

    if ( fCellID[copyIDinZ][copyIDinPhi] == -1 )
    {
        CalorimeterHit* calHit = new CalorimeterHit(physVol->GetLogicalVolume(), copyIDinZ, copyIDinPhi);
        calHit-> SetEdep(edep);
        G4AffineTransform aTrans = ROhist->GetHistory()->GetTopTransform();
        aTrans.Invert();
        calHit-> SetPos(aTrans.NetTranslation());
        calHit-> SetRot(aTrans.NetRotation());
        G4int icell = fCalCollection->insert(calHit);
        fCellID[copyIDinZ][copyIDinPhi] = icell - 1;
        if(verboseLevel>0)
            G4cout << " New Calorimeter Hit on CellID " << copyIDinZ << " " << copyIDinPhi << G4endl;
        else
            (*fCalCollection)[fCellID[copyIDinZ][copyIDinPhi]]-> AddEdep(edep);

        if ( verboseLevel > 0 )
            G4cout << " Energy added to CellID " << copyIDinZ << " " << copyIDinPhi << G4endl;
    }

    return true;
}


void CalorimeterSD::EndOfEvent(G4HCofThisEvent*HCE)
{
    static G4int HCID = -1;
    if ( HCID < 0 )
        HCID = GetCollectionID(0);

    HCE-> AddHitsCollection(HCID, fCalCollection );
}


void CalorimeterSD::clear()
{}


void CalorimeterSD::DrawAll()
{}


void CalorimeterSD::PrintAll()
{}
