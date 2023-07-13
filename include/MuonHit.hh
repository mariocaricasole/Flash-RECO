#ifndef MUON_HIT_HH
#define MUON_HIT_HH

#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

class MuonHit : public G4VHit {
public:
    MuonHit();
    ~MuonHit();
    MuonHit(const MuonHit& right);
    const MuonHit& operator=(const MuonHit &right);
    G4bool operator==(const MuonHit &right) const;

    inline void *operator new(size_t);
    inline void operator delete(void *aHit);

    virtual void Draw();
    virtual void Print();

    inline void SetEdep(G4double de) { fedep = de; }
    inline void AddEdep(G4double de) { fedep += de; }
    inline G4double GetEdep() { return fedep; }
    inline void SetPos(G4ThreeVector xyz) { fpos = xyz; }
    inline G4ThreeVector GetPos() { return fpos; }

private:
    G4double fedep;
    G4ThreeVector fpos;
};


typedef G4THitsCollection<MuonHit> MuonHitsCollection;

extern G4Allocator<MuonHit> MuonHitAllocator;

inline void* MuonHit::operator new(size_t)
{
    void* aHit;
    aHit = (void *) MuonHitAllocator.MallocSingle();
    return aHit;
}

inline void MuonHit::operator delete(void *aHit)
{
    MuonHitAllocator.FreeSingle((MuonHit*) aHit);
}

#endif
