#ifndef GAMMACONSTRUCT_HH
#define GAMMACONSTRUCT_HH 

#include "G4SystemOfUnits.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4Box.hh"

class GammaDetectorConstructor : public G4VUserDetectorConstruction
{
public:
    GammaDetectorConstructor();
    ~GammaDetectorConstructor();

    virtual G4VPhysicalVolume *Construct();
    G4LogicalVolume *GammaMakeCement(G4Box *object);
};
#endif