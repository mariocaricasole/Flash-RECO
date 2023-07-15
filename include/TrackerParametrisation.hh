#ifndef TRACKER_PARAMETRISATION_HH
#define TRACKER_PARAMETRISATION_HH

#include "globals.hh"
#include "G4VPVParameterisation.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4Tubs.hh"
#include "G4VPhysicalVolume.hh"

class TrackerParametrisation : public G4VPVParameterisation {
public:
    //constructor/destructor
    TrackerParametrisation();
    virtual ~TrackerParametrisation();

    //compute transformation to place daughter volume
    virtual void ComputeTransformation(const G4int copyNo, G4VPhysicalVolume* physVol) const;

    //compute dimensions of daughter volume
    virtual void ComputeDimensions(G4Tubs& trackerLayer, const G4int copyNo, const G4VPhysicalVolume* physVol) const;

private:
    #include "DetectorParameterDef.hh"
};

#endif
