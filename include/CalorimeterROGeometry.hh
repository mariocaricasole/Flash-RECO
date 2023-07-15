#ifndef CALORIMETER_RO_GEOMETRY_HH
#define CALORIMETER_RO_GEOMETRY_HH

#include "G4VReadOutGeometry.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4Material.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4Tubs.hh"
#include "G4VPhysicalVolume.hh"

class CalorimeterROGeometry : public G4VReadOutGeometry {
public:
    //constructors
    CalorimeterROGeometry();
    CalorimeterROGeometry(G4String);

    //destructors
    ~CalorimeterROGeometry();

private:
    virtual G4VPhysicalVolume* Build();
    #include "DetectorParameterDef.hh"

};

#endif
