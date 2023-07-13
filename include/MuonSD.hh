#ifndef MUON_SD_HH
#define MUON_SD_HH

#include "G4VSensitiveDetector.hh"
#include "MuonHit.hh"

class G4Step;
class G4HCofThisEvent;
class G4TouchableHistory;

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
