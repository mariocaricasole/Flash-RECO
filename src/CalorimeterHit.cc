#include "CalorimeterHit.hh"

//defining the allocator
G4Allocator<CalorimeterHit> CalorimeterHitAllocator;

//constructors
CalorimeterHit::CalorimeterHit() : G4VHit(), fpLogV(NULL)
{}

CalorimeterHit::CalorimeterHit(G4LogicalVolume* logVol, G4int z, G4int phi) : fZCellID(z), fPhiCellID(phi), fpLogV(logVol)
{}

CalorimeterHit::CalorimeterHit(const CalorimeterHit &right) : G4VHit()
{
    fZCellID = right.fZCellID;
    fPhiCellID = right.fPhiCellID;
    fedep = right.fedep;
    fpos = right.fpos;
    frot = right.frot;
    fpLogV = right.fpLogV;
}

//destructor
CalorimeterHit::~CalorimeterHit()
{}


//assign/compare operators
const CalorimeterHit& CalorimeterHit::operator=(const CalorimeterHit &right)
{
    fZCellID = right.fZCellID;
    fPhiCellID = right.fPhiCellID;
    fedep = right.fedep;
    fpos = right.fpos;
    frot = right.frot;
    fpLogV = right.fpLogV;

    return *this;
}

G4bool CalorimeterHit::operator==(const CalorimeterHit &right) const
{
    return ( (fZCellID == right.fZCellID) && (fPhiCellID == right.fPhiCellID) );
}


//Draw method to show the hits in the interactive mode
void CalorimeterHit::Draw()
{
    G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();

    if(pVVisManager)
    {
        G4Transform3D trans(frot, fpos);
        G4VisAttributes attribs;
        const G4VisAttributes* pVA = fpLogV-> GetVisAttributes();
        if ( pVA )
            attribs = *pVA;
        G4Colour colour(1., 0., 0.);
        attribs.SetColour(colour);
        attribs.SetForceWireframe(false);
        attribs.SetForceSolid(true);
        pVVisManager-> Draw(*fpLogV, attribs, trans);
    }
}

void CalorimeterHit::Print()
{}
