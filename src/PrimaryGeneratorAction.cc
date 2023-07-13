#include "PrimaryGeneratorAction.hh"
#include "PrimaryGeneratorMessenger.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "HepMCG4AsciiReader.hh"
#include "HepMCG4PythiaInterface.hh"


PrimaryGeneratorAction::PrimaryGeneratorAction() : G4VUserPrimaryGeneratorAction()
{
    // default generator is particle gun.
    fCurrentGenerator = fParticleGun= new G4ParticleGun();
    fCurrentGeneratorName = "fParticleGun";
    fHepmcAscii = new HepMCG4AsciiReader();
    #ifdef G4LIB_USE_PYTHIA
    fPythiaGen = new HepMCG4PythiaInterface();
    #else
    fPythiaGen = 0;
    #endif
    fGentypeMap["particleGun"] = fParticleGun;
    fGentypeMap["hepmcAscii"] = fHepmcAscii;
    fGentypeMap["pythia"] = fPythiaGen;

    fMessenger= new PrimaryGeneratorMessenger(this);
}


PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fMessenger;
}


void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    if(fCurrentGenerator)
        fCurrentGenerator-> GeneratePrimaryVertex(anEvent);
    else
        G4Exception("PrimaryGeneratorAction::GeneratePrimaries", "PrimaryGeneratorAction001", FatalException, "generator is not instanciated." );
}
