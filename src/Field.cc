#include "G4SystemOfUnits.hh"
#include "Field.hh"


Field::Field() : G4MagneticField()
{
    fBz = 3.0*tesla;
    frmax_sq = sqr(50.*cm);
    fzmax = 100.*cm;
}


Field::~Field()
{}


void Field::GetFieldValue(const double Point[3],double *Bfield) const
{
    Bfield[0] = 0.;
    Bfield[1] = 0.;
    if ( std::abs(Point[2]) < fzmax && (sqr(Point[0])+sqr(Point[1])) < frmax_sq ) {
        Bfield[2] = fBz;
    }
    else
    {
        Bfield[2] = 0.;
    }
}
