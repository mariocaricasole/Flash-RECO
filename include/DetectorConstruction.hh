#ifndef	DETECTOR_CONSTRUCTION_HH
#define DETECTOR_CONSTRUCTION_HH

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4Material;

class DetectorConstruction : public G4VUserDetectorConstruction {
public:
    DetectorConstruction();
    ~DetectorConstruction();

    virtual G4VPhysicalVolume* Construct();

private:
    void DefineMaterials();

#include "DetectorParameterDef.hh"

    G4Material* fAir;
    G4Material* fAr;
    G4Material* fSilicon;
    G4Material* fScinti;
    G4Material* fLead;
};

#endif
