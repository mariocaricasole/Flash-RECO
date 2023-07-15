#ifndef PRIMARY_GENERATOR_ACTION_HH
#define PRIMARY_GENERATOR_ACTION_HH

#include <map>

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "globals.hh"

#include "HepMCG4AsciiReader.hh"

class G4Event;
class G4VPrimaryGenerator;
class PrimaryGeneratorMessenger;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
	PrimaryGeneratorAction();
	~PrimaryGeneratorAction();

	//generate primary vertexes routine
	virtual void GeneratePrimaries(G4Event*);

private:
	//HepMC3 ascii file reader
	HepMCG4AsciiReader *asciiInput;
};

#endif
