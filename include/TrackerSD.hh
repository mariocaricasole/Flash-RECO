#ifndef TRACKER_SD_HH
#define TRACKER_SD_HH

#include "G4VSensitiveDetector.hh"
#include "TrackerHit.hh"

class G4Step;
class G4HCofThisEvent;
class G4TouchableHistory;

class TrackerSD : public G4VSensitiveDetector {
public:
    TrackerSD(G4String name);
    ~TrackerSD();

    virtual void Initialize(G4HCofThisEvent*HCE);
    virtual G4bool ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist);
    virtual void EndOfEvent(G4HCofThisEvent*HCE);
    virtual void clear();
    virtual void DrawAll();
    virtual void PrintAll();

private:
    TrackerHitsCollection* fTrackerCollection;

};

#endif
