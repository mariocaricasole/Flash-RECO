#ifndef CALORIMETER_PARAMETRISATION_HH
#define CALORIMETER_PARAMETRISATION_HH

#include "globals.hh"
#include "G4VPVParameterisation.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4Tubs.hh"
#include "G4VPhysicalVolume.hh"

class CalorimeterParametrisation : public G4VPVParameterisation {
public:
    //constructor/destructor
    CalorimeterParametrisation();
    virtual ~CalorimeterParametrisation();

    //compute transformation to place daughter volume
    virtual void ComputeTransformation(const G4int copyNo, G4VPhysicalVolume* physVol) const;
    //compute dimensions of daughter volume
    virtual void ComputeDimensions(G4Tubs& calorimeterLayer, const G4int copyNo, const G4VPhysicalVolume * physVol) const;

private:
    //import detector parameter declarations
    #include "DetectorParameterDef.hh"
};

#endif
