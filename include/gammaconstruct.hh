#ifndef GAMMACONSTRUCT_HH
#define GAMMACONSTRUCT_HH 

#include "G4SystemOfUnits.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VUserDetectorConstruction.hh"

class GammaDetectorConstructor : public G4VUserDetectorConstruction
{
public:
    GammaDetectorConstructor();
    ~GammaDetectorConstructor();

    virtual G4VPhysicalVolume *Construct();
};
#endif