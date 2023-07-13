#ifndef TRACKER_PARAMETRISATION_HH
#define TRACKER_PARAMETRISATION_HH

#include "globals.hh"
#include "G4VPVParameterisation.hh"

class G4Tubs;
class G4VPhysicalVolume;

// Dummy declarations to get rid of warnings ...
class G4Box;
class G4Cons;
class G4Ellipsoid;
class G4Hype;
class G4Orb;
class G4Para;
class G4Polycone;
class G4Polyhedra;
class G4Sphere;
class G4Torus;
class G4Trap;
class G4Trd;

class TrackerParametrisation : public G4VPVParameterisation {
public:
    TrackerParametrisation();
    virtual ~TrackerParametrisation();
    virtual void ComputeTransformation(const G4int copyNo,
                            G4VPhysicalVolume* physVol) const;
    virtual void ComputeDimensions(G4Tubs& trackerLayer, const G4int copyNo,
                            const G4VPhysicalVolume* physVol) const;

private:  // Dummy declarations to get rid of warnings ...
    virtual void ComputeDimensions(G4Trd&,const G4int,
                            const G4VPhysicalVolume*) const {}
    virtual void ComputeDimensions(G4Trap&,const G4int,
                            const G4VPhysicalVolume*) const {}
    virtual void ComputeDimensions(G4Cons&,const G4int,
                            const G4VPhysicalVolume*) const {}
    virtual void ComputeDimensions(G4Orb&,const G4int,
                            const G4VPhysicalVolume*) const {}
    virtual void ComputeDimensions(G4Sphere&,const G4int,
                            const G4VPhysicalVolume*) const {}
    virtual void ComputeDimensions(G4Ellipsoid&,const G4int,
                            const G4VPhysicalVolume*) const {}
    virtual void ComputeDimensions(G4Torus&,const G4int,
                            const G4VPhysicalVolume*) const {}
    virtual void ComputeDimensions(G4Para&, const G4int,
                            const G4VPhysicalVolume*) const {}
    virtual void ComputeDimensions(G4Hype&, const G4int,
                            const G4VPhysicalVolume*) const {}
    virtual void ComputeDimensions(G4Box&,const G4int,
                            const G4VPhysicalVolume*) const {}
    virtual void ComputeDimensions(G4Polycone&,const G4int,
                            const G4VPhysicalVolume*) const {}
    virtual void ComputeDimensions(G4Polyhedra&, const G4int,
                            const G4VPhysicalVolume*) const {}

#include "DetectorParameterDef.hh"

};

#endif
