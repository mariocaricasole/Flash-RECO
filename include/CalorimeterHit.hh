#ifndef CALORIMETER_HIT_HH
#define CALORIMETER_HIT_HH

#include "G4Allocator.hh"
#include "G4LogicalVolume.hh"
#include "G4RotationMatrix.hh"
#include "G4THitsCollection.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4VHit.hh"

class CalorimeterHit : public G4VHit {
public:
    CalorimeterHit();
    CalorimeterHit(G4LogicalVolume* logVol, G4int z, G4int phi);
    CalorimeterHit(const CalorimeterHit& right);

    virtual ~CalorimeterHit();

    const CalorimeterHit& operator=(const CalorimeterHit& right);
    G4bool operator==(const CalorimeterHit& right) const;

    inline void* operator new(size_t);
    inline void operator delete(void* aHit);

    virtual void Draw();
    virtual void Print();

    void SetCellID(G4int z,G4int phi);
    G4int GetZ();
    G4int GetPhi();
    void SetEdep(G4double de);
    void AddEdep(G4double de);
    G4double GetEdep();
    void SetPos(G4ThreeVector xyz);
    G4ThreeVector GetPos();
    void SetRot(G4RotationMatrix rmat);
    G4RotationMatrix GetRot();
    const G4LogicalVolume* GetLogV();

private:
    G4int fZCellID;
    G4int fPhiCellID;
    G4double fedep;
    G4ThreeVector fpos;
    G4RotationMatrix frot;
    const G4LogicalVolume* fpLogV;
};


inline void CalorimeterHit::SetCellID(G4int z,G4int phi)
 {
    fZCellID = z;
    fPhiCellID = phi;
}

inline G4int CalorimeterHit::GetZ()
{
    return fZCellID;
}

inline G4int CalorimeterHit::GetPhi()
{
    return fPhiCellID;
}

inline void CalorimeterHit::SetEdep(G4double de)
{
    fedep = de;
}

inline void CalorimeterHit::AddEdep(G4double de)
{
    fedep += de;
}

inline G4double CalorimeterHit::GetEdep()
{
    return fedep;
}

inline void CalorimeterHit::SetPos(G4ThreeVector xyz)
{
    fpos = xyz;
}

inline G4ThreeVector CalorimeterHit::GetPos()
{
    return fpos;
}

inline void CalorimeterHit::SetRot(G4RotationMatrix rmat)
{
    frot = rmat;
}

inline G4RotationMatrix CalorimeterHit::GetRot()
{
    return frot;
}

inline const G4LogicalVolume * CalorimeterHit::GetLogV()
{
    return fpLogV;
}


typedef G4THitsCollection<CalorimeterHit> CalorimeterHitsCollection;

extern G4Allocator<CalorimeterHit> CalorimeterHitAllocator;

inline void* CalorimeterHit::operator new(size_t)
{
    void* aHit;
    aHit = (void*) CalorimeterHitAllocator.MallocSingle();
    return aHit;
}

inline void CalorimeterHit::operator delete(void* aHit)
{
    CalorimeterHitAllocator.FreeSingle((CalorimeterHit*) aHit);
}

#endif
