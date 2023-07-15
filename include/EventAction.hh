#ifndef EVENT_ACTION_HH
#define EVENT_ACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4ios.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UImanager.hh"
#include "G4VHitsCollection.hh"
#include "globals.hh"

#include "CalorimeterHit.hh"
#include "MuonHit.hh"
#include "TrackerHit.hh"

class EventAction : public G4UserEventAction {
public:
    EventAction();
    ~EventAction();

    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);

private:
    G4int ftrackerCollID;
    G4int fcalorimeterCollID;
    G4int fmuonCollID;
};

#endif
