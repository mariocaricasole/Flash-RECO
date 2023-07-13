#ifndef TRACKER_HIT_HH
#define TRACKER_HIT_HH

#include "G4Allocator.hh"
#include "G4THitsCollection.hh"
#include "G4ThreeVector.hh"
#include "G4VHit.hh"

class TrackerHit : public G4VHit {
public:
    TrackerHit();
    ~TrackerHit();
    TrackerHit(const TrackerHit &right);
    const TrackerHit& operator=(const TrackerHit &right);
    G4bool operator==(const TrackerHit &right) const;

    inline void *operator new(size_t);
    inline void operator delete(void *aHit);

    virtual void Draw();
    virtual void Print();

    inline void SetEdep(G4double de) { fEdep = de; }
    inline G4double GetEdep() { return fEdep; }
    inline void SetPos(G4ThreeVector xyz) { fPos = xyz; }
    inline G4ThreeVector GetPos() { return fPos; }

private:
    G4double fEdep;
    G4ThreeVector fPos;
};


typedef G4THitsCollection<TrackerHit> TrackerHitsCollection;


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
