#ifndef TRACKER_HIT_HH
#define TRACKER_HIT_HH

#include "G4Allocator.hh"
#include "G4THitsCollection.hh"
#include "G4ThreeVector.hh"
#include "G4VHit.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

class TrackerHit : public G4VHit {
public:
    //constructors
    TrackerHit();
    TrackerHit(const TrackerHit &right);

    //destructor
    ~TrackerHit();

    //assign/compare operators
    const TrackerHit& operator=(const TrackerHit &right);
    G4bool operator==(const TrackerHit &right) const;

    inline void *operator new(size_t);
    inline void operator delete(void *aHit);

    virtual void Draw();
    virtual void Print();

    //set/get methods
    inline void SetEdep(G4double de) { fEdep = de; }
    inline G4double GetEdep() { return fEdep; }

    inline void SetPos(G4ThreeVector xyz) { fPos = xyz; }
    inline G4ThreeVector GetPos() { return fPos; }

private:
    G4double fEdep;
    G4ThreeVector fPos;
};



/*****************************************************************
 *              INLINE FUNCTIONS DEFINITIONS                     *
/****************************************************************/

//declaring type for the collection of tracker hits
typedef G4THitsCollection<TrackerHit> TrackerHitsCollection;

//declaring an allocator to add or delete memory space for a tracker hit
extern G4Allocator<TrackerHit> TrackerHitAllocator;

inline void* TrackerHit::operator new(size_t)
{
    void* aHit;
    aHit = (void *) TrackerHitAllocator.MallocSingle();
    return aHit;
}

inline void TrackerHit::operator delete(void *aHit)
{
    TrackerHitAllocator.FreeSingle((TrackerHit*) aHit);
}

#endif
