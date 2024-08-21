#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4Step.hh"
#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4VSensitiveDetector.hh"


//Logger for hit energies
class HitAccu : public G4VHit
{
public:
    HitAccu() : edep(0) {}
    virtual ~HitAccu() {}

    inline void AddEdep(G4double nrg);
    G4double edep;
};

class GammaSensitive : public G4VSensitiveDetector
{
public:
    GammaSensitive(const G4String &name) : G4VSensitiveDetector(name) {}
    ~GammaSensitive();

    virtual G4bool ProcessHits(G4Step* step, G4TouchableHistory*) override;
    virtual void Initialize(G4HCofThisEvent* HCE) override;
    virtual void EndOfEvent(G4HCofThisEvent*) override;
private:
    G4THitsCollection<HitAccu>* hits;
};

#endif