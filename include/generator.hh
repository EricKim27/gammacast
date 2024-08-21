#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4RandomTools.hh"
#include "G4Gamma.hh"

class GammaPrimaryGen : public G4VUserPrimaryGeneratorAction
{
public:
    GammaPrimaryGen();
    ~GammaPrimaryGen();

    virtual void GeneratePrimaries(G4Event*);
private:
    G4ParticleGun *pGun;
};

#endif