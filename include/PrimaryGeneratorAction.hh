#ifndef PRIMARY_GENERATOR_ACTION_HH
#define PRIMARY_GENERATOR_ACTION_HH

#include <map>
#include "globals.hh"
#include "G4VUserPrimaryGeneratorAction.hh"

class G4Event;
class G4VPrimaryGenerator;
class PrimaryGeneratorMessenger;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event* anEvent);

    void SetGenerator(G4VPrimaryGenerator* gen);
    void SetGenerator(G4String genname);

    G4VPrimaryGenerator* GetGenerator() const;
    G4String GetGeneratorName() const;

private:
    G4VPrimaryGenerator* fParticleGun;
    G4VPrimaryGenerator* fHepmcAscii;
    G4VPrimaryGenerator* fPythiaGen;

    G4VPrimaryGenerator* fCurrentGenerator;
    G4String fCurrentGeneratorName;
    std::map<G4String, G4VPrimaryGenerator*> fGentypeMap;

    PrimaryGeneratorMessenger* fMessenger;
};


inline void PrimaryGeneratorAction::SetGenerator(G4VPrimaryGenerator* gen)
{
    fCurrentGenerator = gen;
}

inline void PrimaryGeneratorAction::SetGenerator(G4String genname)
{
    std::map<G4String, G4VPrimaryGenerator*>::iterator pos =
                                                fGentypeMap.find(genname);
    if ( pos != fGentypeMap.end() ) {
        fCurrentGenerator = pos->second;
        fCurrentGeneratorName = genname;
  }
}

inline G4VPrimaryGenerator* PrimaryGeneratorAction::GetGenerator() const
{
    return fCurrentGenerator;
}

inline G4String PrimaryGeneratorAction::GetGeneratorName() const
{
    return fCurrentGeneratorName;
}

#endif
