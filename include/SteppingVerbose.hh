#ifndef STEPPING_VERBOSE_HH
#define STEPPING_VERBOSE_HH

#include "G4SteppingVerbose.hh"
#include "G4SteppingManager.hh"
#include "G4UnitsTable.hh"

class SteppingVerbose;


class SteppingVerbose : public G4SteppingVerbose {
public:
    SteppingVerbose();
    ~SteppingVerbose();

    void StepInfo();
    void TrackingStarted();
};

#endif
