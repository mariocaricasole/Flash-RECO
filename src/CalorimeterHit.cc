#include "G4Colour.hh"
#include "G4LogicalVolume.hh"
#include "G4VisAttributes.hh"
#include "G4VVisManager.hh"
#include "CalorimeterHit.hh"

G4Allocator<CalorimeterHit> CalorimeterHitAllocator;


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


CalorimeterHit::~CalorimeterHit()
{}


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
