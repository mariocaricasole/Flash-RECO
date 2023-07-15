#ifndef	STACKING_ACTION_HH
#define STACKING_ACTION_HH

#include "globals.hh"
#include "G4ThreeVector.hh"
#include "G4UserStackingAction.hh"
#include "G4SDManager.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4HCofThisEvent.hh"
#include "G4Track.hh"
#include "G4TrackStatus.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4SystemOfUnits.hh"

#include "TrackerHit.hh"
#include "MuonHit.hh"

//dummy class to avoid warnings
class StackingActionMessenger;

class StackingAction : public G4UserStackingAction {
public:
    StackingAction();
    virtual ~StackingAction();

    virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track* aTrack);
    virtual void NewStage();
    virtual void PrepareNewEvent();

    inline void SetNRequestMuon(G4int val) { fReqMuon = val; }
    inline G4int GetNRequestMuon() const { return fReqMuon; }
    inline void SetNRequestIsoMuon(G4int val) { fReqIsoMuon = val; }
    inline G4int GetNRequestIsoMuon() const { return fReqIsoMuon; }
    inline void SetNIsolation(G4int val) { fReqIso = val; }
    inline G4int GetNIsolation() const { return fReqIso; }
    inline void SetRoIAngle(G4double val) { fAngRoI = val; }
    inline G4double GetRoIAngle() const { return fAngRoI; }

private:
    G4bool InsideRoI(const G4Track * aTrack,G4double ang);
    G4VHitsCollection* GetCollection(G4String colName);

    TrackerHitsCollection* fTrkHits;
    MuonHitsCollection* fMuonHits;
    StackingActionMessenger* fMessenger;

    G4int fStage;
    G4int fReqMuon;
    G4int fReqIsoMuon;
    G4int fReqIso;
    G4double fAngRoI;
};

#endif
