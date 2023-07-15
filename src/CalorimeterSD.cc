#include "CalorimeterSD.hh"

//constructor
CalorimeterSD::CalorimeterSD(G4String name) : G4VSensitiveDetector(name), fCalCollection(NULL), fnumberOfCellsInZ(20), fnumberOfCellsInPhi(48)
{
    G4String HCname;
    collectionName.insert(HCname="calCollection");
}

//destructor
CalorimeterSD::~CalorimeterSD()
{}


void CalorimeterSD::Initialize(G4HCofThisEvent*)
{
    //make a new calorimeter hits collection object
    fCalCollection = new CalorimeterHitsCollection(SensitiveDetectorName, collectionName[0]);

    //set the id of each cell to -1 (inactive)
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
    //if the touchable history is already filled, don't proceed
    if ( !ROhist )
        return false;

    //get the total energy deposited during the step
    G4double edep = aStep-> GetTotalEnergyDeposit();

    //if verbose>1 tell the energy deposited in the next step
    if ( verboseLevel > 1 )
        G4cout << "Next step edep(MeV) = " << edep/MeV << G4endl;

    //if no energy is deposited, no need to proceed
    if ( edep == 0. )
        return false;

    //get the touchable volumes and the indexes of a particular copy
    G4VPhysicalVolume* physVol = ROhist-> GetVolume();
    //ROhist->MoveUpHistory();
    //G4VPhysicalVolume* mothVol = ROhist->GetVolume(1);
    G4int copyIDinZ = ROhist-> GetReplicaNumber();
    G4int copyIDinPhi = ROhist-> GetReplicaNumber(1);

    //if the cell hasn't been activated yet
    if ( fCellID[copyIDinZ][copyIDinPhi] == -1 )
    {
        //build a new calorimeter hit object and deposit the energy on it
        CalorimeterHit* calHit = new CalorimeterHit(physVol->GetLogicalVolume(), copyIDinZ, copyIDinPhi);
        calHit-> SetEdep(edep);

        //set also the position and orientation of the hit
        G4AffineTransform aTrans = ROhist->GetHistory()->GetTopTransform();
        aTrans.Invert();
        calHit-> SetPos(aTrans.NetTranslation());
        calHit-> SetRot(aTrans.NetRotation());

        //assign to the cell the number of hits
        G4int icell = fCalCollection->insert(calHit);
        fCellID[copyIDinZ][copyIDinPhi] = icell - 1;

        //if verbose, tell the user a new hit in ij cell has been detected, otherwise just add the energy deposited in the collection
        if(verboseLevel>0)
            G4cout << " New Calorimeter Hit on CellID " << copyIDinZ << " " << copyIDinPhi << G4endl;
        else
            (*fCalCollection)[fCellID[copyIDinZ][copyIDinPhi]]-> AddEdep(edep);

        //if verbose, tell the user how much energy has been deposited in the cell
        if ( verboseLevel > 0 )
            G4cout << " Energy added to CellID " << copyIDinZ << " " << copyIDinPhi << G4endl;
    }

    return true;
}


void CalorimeterSD::EndOfEvent(G4HCofThisEvent*HCE)
{
    //at the end of the event, get the collection ID
    static G4int HCID = -1;
    if ( HCID < 0 )
        HCID = GetCollectionID(0);

    //add hits collection
    HCE-> AddHitsCollection(HCID, fCalCollection );
}


void CalorimeterSD::clear()
{}


void CalorimeterSD::DrawAll()
{}


void CalorimeterSD::PrintAll()
{}
