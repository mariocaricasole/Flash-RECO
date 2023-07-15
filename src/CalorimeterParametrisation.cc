#include "CalorimeterParametrisation.hh"

//constructor, importing parameters values
CalorimeterParametrisation::CalorimeterParametrisation() : G4VPVParameterisation()
{
    #include "DetectorParameterDef.icc"
}

//destructor
CalorimeterParametrisation::~CalorimeterParametrisation()
{}

//compute transformation to place daughter volume
void CalorimeterParametrisation::ComputeTransformation(const G4int, G4VPhysicalVolume* physVol) const
{
    G4ThreeVector origin;
    physVol-> SetTranslation(origin);
}

//compute dimensions of daughter volume
void CalorimeterParametrisation::ComputeDimensions(G4Tubs& calorimeterLayer, const G4int copyNo, const G4VPhysicalVolume*) const
{
    G4double innerRad = fcaloTubs_rmin + copyNo * (fabsorber_thick + fscinti_thick);
    calorimeterLayer.SetInnerRadius(innerRad);
    calorimeterLayer.SetOuterRadius(innerRad + fabsorber_thick);
    calorimeterLayer.SetZHalfLength(fcaloTubs_dz);
    calorimeterLayer.SetStartPhiAngle(fcaloTubs_sphi);
    calorimeterLayer.SetDeltaPhiAngle(fcaloTubs_dphi);
}
