#ifndef CALORIMETER_RO_GEOMETRY_HH
#define CALORIMETER_RO_GEOMETRY_HH

#include "G4VReadOutGeometry.hh"

class CalorimeterROGeometry : public G4VReadOutGeometry {
public:
    CalorimeterROGeometry();
    CalorimeterROGeometry(G4String);
    ~CalorimeterROGeometry();

private:
    virtual G4VPhysicalVolume* Build();

#include "DetectorParameterDef.hh"

};

#endif
