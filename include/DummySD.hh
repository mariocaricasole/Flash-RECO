#ifndef DUMMY_SD_HH
#define DUMMY_SD_HH

#include "G4VSensitiveDetector.hh"
#include "G4Step.hh"

class DummySD : public G4VSensitiveDetector {
public:
    DummySD();
    ~DummySD() {}

    virtual void Initialize(G4HCofThisEvent*) {}
    virtual G4bool ProcessHits(G4Step*,G4TouchableHistory*) {return false;}
    virtual void EndOfEvent(G4HCofThisEvent*) {}
    virtual void clear() {}
    virtual void DrawAll() {}
    virtual void PrintAll() {}
};

DummySD::DummySD() : G4VSensitiveDetector("dummySD")
{}

#endif
