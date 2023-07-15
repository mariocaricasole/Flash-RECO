#ifndef MUON_SD_HH
#define MUON_SD_HH

#include "G4VSensitiveDetector.hh"
#include "G4HCofThisEvent.hh"
#include "G4ios.hh"
#include "G4Step.hh"
#include "G4SystemOfUnits.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"

#include "MuonHit.hh"

class MuonSD : public G4VSensitiveDetector {
public:
    MuonSD(G4String name);
    ~MuonSD();

    virtual void Initialize(G4HCofThisEvent* HCE);
    virtual G4bool ProcessHits(G4Step* aStep, G4TouchableHistory* ROhist);
    virtual void EndOfEvent(G4HCofThisEvent* HCE);
    virtual void clear();
    virtual void DrawAll();
    virtual void PrintAll();

private:
    MuonHitsCollection * fMuonCollection;
    G4double fPositionResolution;

};

#endif
