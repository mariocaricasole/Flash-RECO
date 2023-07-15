#ifndef FIELD_HH
#define FIELD_HH

#include "G4MagneticField.hh"
#include "G4SystemOfUnits.hh"
#include "globals.hh"

class Field : public G4MagneticField {
public:
    Field();
    ~Field();

    virtual void GetFieldValue( const  double Point[3], double *Bfield ) const;

private:
    G4double fBz;
    G4double frmax_sq;
    G4double fzmax;
};

#endif
