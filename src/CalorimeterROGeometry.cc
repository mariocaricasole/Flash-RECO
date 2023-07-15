#include "CalorimeterROGeometry.hh"
#include "DummySD.hh"


//constructors
CalorimeterROGeometry::CalorimeterROGeometry() : G4VReadOutGeometry()
{
    #include "DetectorParameterDef.icc"
}

CalorimeterROGeometry::CalorimeterROGeometry(G4String aString) : G4VReadOutGeometry(aString)
{
    #include "DetectorParameterDef.icc"
}


//destructor
CalorimeterROGeometry::~CalorimeterROGeometry()
{}

//build a new world and geometry only for the readout
G4VPhysicalVolume* CalorimeterROGeometry::Build()
{
    // A dummy material is used to fill the volumes of the readout geometry.
    // ( It will be allowed to set a NULL pointer in volumes of such virtual
    // division in future, since this material is irrelevant for tracking.)

    G4Material* dummyMat  = new G4Material(name="dummyMat", 1., 1.*g/mole, 1.*g/cm3);

    //Builds the ReadOut World:
    G4Box* ROWorldBox = new G4Box("ROWorldBox", fexpHall_x, fexpHall_y, fexpHall_z);
    G4LogicalVolume* ROWorldLog = new G4LogicalVolume(ROWorldBox, dummyMat, "ROWorldLogical", 0, 0, 0);
    G4PVPlacement* ROWorldPhys = new G4PVPlacement(0, G4ThreeVector(), "ROWorldPhysical", ROWorldLog, 0, false, 0);

    // Calorimeter volume:
    G4VSolid* caloROtub = new G4Tubs("caloROtub", fcaloTubs_rmin, fcaloTubs_rmax, fcaloTubs_dz, fcaloTubs_sphi, fcaloTubs_dphi);
    G4LogicalVolume* caloROlog = new G4LogicalVolume(caloROtub, dummyMat, "caloROlogical",0,0,0);
    G4VPhysicalVolume* caloROphys = new G4PVPlacement(0, G4ThreeVector(), "calROphysical", caloROlog, ROWorldPhys, false, 0);

    // -------------------------------
    // Calorimeter readout division:
    // -------------------------------

    // Phi division first: 48 sectors
    G4VSolid* caloROphiDivisionTub = new G4Tubs("caloROphiDivision", fcaloCell_rmin, fcaloCell_rmax, fcaloCell_dz, fcaloCell_sphi, fcaloCell_dphi);
    G4LogicalVolume* caloROphiDivisionLog = new G4LogicalVolume(caloROphiDivisionTub, dummyMat, "caloROphiDivisionLogical",0,0,0);
    G4VPhysicalVolume* caloROphiDivisionPhys = new G4PVReplica("caloROphiDivisionPhysical", caloROphiDivisionLog, caloROphys, kPhi, fsegmentsinPhi, fcaloCell_dphi);

    // then z division: 20 slices:
    G4VSolid* caloROcellTub = new G4Tubs("caloROcellTub", fcaloRing_rmin, fcaloRing_rmax, fcaloRing_dz, fcaloRing_sphi, fcaloRing_dphi);
    G4LogicalVolume* caloROcellLog = new G4LogicalVolume(caloROcellTub, dummyMat, "caloROcellLogical",0,0,0);
    //  G4VPhysicalVolume * caloROcellPhys =
    new G4PVReplica("caloROcellPhysical", caloROcellLog, caloROphiDivisionPhys, kZAxis, fsegmentsinZ, 2.*fcaloRing_dz);


    //Flags the cells as sensitive .The pointer here serves
    // as a flag only to check for sensitivity.
    // (Could we make it by a simple cast of a non-NULL value ?)
    DummySD * dummySensi = new DummySD;
    caloROcellLog->SetSensitiveDetector(dummySensi);

    return ROWorldPhys;
}
