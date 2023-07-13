#ifndef EVENT_ACTION_HH
#define EVENT_ACTION_HH

#include "G4UserEventAction.hh"
#include "globals.hh"

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
