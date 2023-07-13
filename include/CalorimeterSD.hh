#ifndef CALORIMETER_SD_HH
#define CALORIMETER_SD_HH

#include "G4VSensitiveDetector.hh"
#include "CalorimeterHit.hh"
class G4Step;
class G4HCofThisEvent;
class G4TouchableHistory;

class CalorimeterSD : public G4VSensitiveDetector {
public:
    CalorimeterSD(G4String name);
    ~CalorimeterSD();

    virtual void Initialize(G4HCofThisEvent*HCE);
    virtual G4bool ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist);
    virtual void EndOfEvent(G4HCofThisEvent*HCE);
    virtual void clear();
    virtual void DrawAll();
    virtual void PrintAll();

private:
    CalorimeterHitsCollection* fCalCollection;
    int fCellID[20][48];
    const int fnumberOfCellsInZ;
    const int fnumberOfCellsInPhi;

};

#endif
