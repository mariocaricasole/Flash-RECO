#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4Tubs.hh"
#include "G4VPhysicalVolume.hh"
#include "TrackerParametrisation.hh"



TrackerParametrisation::TrackerParametrisation() : G4VPVParameterisation()
{
#include "DetectorParameterDef.icc"
}


TrackerParametrisation::~TrackerParametrisation()
{}


void TrackerParametrisation::ComputeTransformation(const G4int, G4VPhysicalVolume* physVol) const
{
    G4ThreeVector origin;
    physVol-> SetTranslation(origin);
}


void TrackerParametrisation::ComputeDimensions(G4Tubs& trackerLayer, const G4int copyNo, const G4VPhysicalVolume*) const
{
    trackerLayer.SetInnerRadius(ftracker_radius[copyNo]);
    trackerLayer.SetOuterRadius(ftracker_radius[copyNo] + ftracker_thick);
    trackerLayer.SetZHalfLength(ftracker_length[copyNo]);
    trackerLayer.SetStartPhiAngle(ftrkTubs_sphi);
    trackerLayer.SetDeltaPhiAngle(ftrkTubs_dphi);
}
