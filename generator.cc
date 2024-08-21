#include "generator.hh"

GammaPrimaryGen::GammaPrimaryGen()
{
    pGun = new G4ParticleGun(1);
}
GammaPrimaryGen::~GammaPrimaryGen()
{
    delete pGun;
}

void GammaPrimaryGen::GeneratePrimaries(G4Event *anEvent)
{
    G4ParticleTable *pTable = G4ParticleTable::GetParticleTable();
    G4String particleName = "Gamma";
    G4ParticleDefinition *gamma = pTable->FindParticle("gamma");
    
    //Make the particle to emit in a cone shape.
    G4double theta = G4UniformRand() * (10.0 * CLHEP::deg); 
    G4double phi = G4UniformRand() * 2 * CLHEP::pi;
    G4double z = std::cos(theta);
    G4double y = std::sin(theta) * std::cos(phi);
    G4double x = std::sin(theta) * std::sin(phi);

    G4ThreeVector pos(0.,0.,0.);
    G4ThreeVector mom(x,y,z);

    pGun->SetParticlePosition(pos);
    pGun->SetParticleMomentumDirection(mom);
    pGun->SetParticleMomentum(100.*MeV);
    pGun->SetParticleDefinition(G4Gamma::Gamma());

    pGun->GeneratePrimaryVertex(anEvent);
}