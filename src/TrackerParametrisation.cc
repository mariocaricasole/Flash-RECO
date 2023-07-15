#include "TrackerParametrisation.hh"

//constructor, importing parameters values
TrackerParametrisation::TrackerParametrisation() : G4VPVParameterisation()
{
    #include "DetectorParameterDef.icc"
}


//destructor
TrackerParametrisation::~TrackerParametrisation()
{}


//compute transformation to place daughter volume
void TrackerParametrisation::ComputeTransformation(const G4int, G4VPhysicalVolume* physVol) const
{
    G4ThreeVector origin;
    physVol-> SetTranslation(origin);
}


//compute dimensions of daughter volume
void TrackerParametrisation::ComputeDimensions(G4Tubs& trackerLayer, const G4int copyNo, const G4VPhysicalVolume*) const
{
    trackerLayer.SetInnerRadius(ftracker_radius[copyNo]);
    trackerLayer.SetOuterRadius(ftracker_radius[copyNo] + ftracker_thick);
    trackerLayer.SetZHalfLength(ftracker_length[copyNo]);
    trackerLayer.SetStartPhiAngle(ftrkTubs_sphi);
    trackerLayer.SetDeltaPhiAngle(ftrkTubs_dphi);
}
