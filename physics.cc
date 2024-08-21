#include "physics.hh"

GammaPhysicsList::GammaPhysicsList()
{
    RegisterPhysics(new G4EmStandardPhysics());
    RegisterPhysics(new G4OpticalPhysics());
}

GammaPhysicsList::~GammaPhysicsList(){}