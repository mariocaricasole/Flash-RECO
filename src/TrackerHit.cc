#include "TrackerHit.hh"

//defining the allocator
G4Allocator<TrackerHit> TrackerHitAllocator;


//constructors
TrackerHit::TrackerHit() : G4VHit(), fEdep(0.), fPos()
{}

TrackerHit::TrackerHit(const TrackerHit &right) : G4VHit()
{
    fEdep = right.fEdep;
    fPos = right.fPos;
}


//destructor
TrackerHit::~TrackerHit()
{}


//assign/compare operators
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


//Draw method to show the hits in the interactive mode
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
