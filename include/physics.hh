#ifndef PHYSICS_HH
#define PHYSICS_HH

#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4RadioactiveDecay.hh"
#include "G4DecayPhysics.hh"
#include "G4opticalPhysics.hh"

class GammaPhysicsList : public G4VModularPhysicsList
{
public:
    GammaPhysicsList();
    ~GammaPhysicsList();
};
#endif