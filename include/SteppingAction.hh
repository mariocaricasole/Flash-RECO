#ifndef STEPPING_ACTION_HH
#define STEPPING_ACTION_HH

#include "globals.hh"
#include "G4UserSteppingAction.hh"

class SteppingAction : public G4UserSteppingAction {
public:
    SteppingAction();
    virtual ~SteppingAction();

    virtual void UserSteppingAction(const G4Step*);
};

#endif
