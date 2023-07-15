#include "MuonHit.hh"

//defining the allocator
G4Allocator<MuonHit> MuonHitAllocator;


//constructors
MuonHit::MuonHit() : G4VHit(), fedep(0.), fpos()
{}

MuonHit::MuonHit(const MuonHit &right) : G4VHit()
{
    fedep = right.fedep;
    fpos = right.fpos;
}


//destructor
MuonHit::~MuonHit()
{}


//assign/compare operators
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


//Draw method to show the hits in the interactive mode
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
