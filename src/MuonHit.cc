#include "MuonHit.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"


G4Allocator<MuonHit> MuonHitAllocator;


MuonHit::MuonHit() : G4VHit(), fedep(0.), fpos()
{}


MuonHit::~MuonHit()
{}


MuonHit::MuonHit(const MuonHit &right) : G4VHit()
{
    fedep = right.fedep;
    fpos = right.fpos;
}


const MuonHit& MuonHit::operator=(const MuonHit &right)
{
    fedep = right.fedep;
    fpos = right.fpos;
    return *this;
}


G4bool MuonHit::operator==(const MuonHit &right) const
{
    return (this==&right) ? true : false;
}


void MuonHit::Draw()
{
    G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
    if(pVVisManager)
    {
        G4Circle circle(fpos);
        circle.SetScreenSize(0.04);
        circle.SetFillStyle(G4Circle::filled);
        G4Colour colour(1.,0.,0.);
        G4VisAttributes attribs(colour);
        circle.SetVisAttributes(attribs);
        pVVisManager->Draw(circle);
    }
}


void MuonHit::Print()
{}
