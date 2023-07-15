#ifndef RUN_ACTION_HH
#define RUN_ACTION_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "globals.hh"

class RunAction : public G4UserRunAction {
public:
    RunAction();
    ~RunAction();

    virtual void BeginOfRunAction(const G4Run*);
};

#endif
