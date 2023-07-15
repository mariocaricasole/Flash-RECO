#ifndef CALORIMETER_SD_HH
#define CALORIMETER_SD_HH

#include "G4VSensitiveDetector.hh"
#include "G4ios.hh"
#include "G4LogicalVolume.hh"
#include "G4ParticleDefinition.hh"
#include "G4Step.hh"
#include "G4SystemOfUnits.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VTouchable.hh"

#include "CalorimeterHit.hh"

class CalorimeterSD : public G4VSensitiveDetector {
public:
    //constructor/destructor
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
