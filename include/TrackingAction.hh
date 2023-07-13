#ifndef TRACKING_ACTION_HH
#define TRACKING_ACTION_HH

#include "G4UserTrackingAction.hh"

class TrackingAction : public G4UserTrackingAction {
public:
    TrackingAction() : G4UserTrackingAction() {};
    virtual ~TrackingAction(){};

    virtual void PreUserTrackingAction(const G4Track*);
};

#endif
