#include "TrackerHit.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"


G4Allocator<TrackerHit> TrackerHitAllocator;


TrackerHit::TrackerHit() : G4VHit(), fEdep(0.), fPos()
{}


TrackerHit::~TrackerHit()
{}


TrackerHit::TrackerHit(const TrackerHit &right) : G4VHit()
{
    fEdep = right.fEdep;
    fPos = right.fPos;
}


const TrackerHit& TrackerHit::operator=(const TrackerHit &right)
{
    fEdep = right.fEdep;
    fPos = right.fPos;
    return *this;
}


G4bool TrackerHit::operator==(const TrackerHit &right) const
{
    return (this==&right) ? true : false;
}


void TrackerHit::Draw()
{
    G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
    if(pVVisManager)
    {
        G4Circle circle(fPos);
        circle.SetScreenSize(0.04);
        circle.SetFillStyle(G4Circle::filled);
        G4Colour colour(1.,0.,0.);
        G4VisAttributes attribs(colour);
        circle.SetVisAttributes(attribs);
        pVVisManager->Draw(circle);
    }
}


void TrackerHit::Print()
{}
