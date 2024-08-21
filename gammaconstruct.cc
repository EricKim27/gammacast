#include "gammaconstruct.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4Box.hh"
#include "detector.hh"

G4Colour red(1.0, 0.0, 0.0);
G4Colour blue(0.0, 0.0, 1.0);
G4Colour green(0.0, 1.0, 0.0);

GammaDetectorConstructor::GammaDetectorConstructor()
{}

GammaDetectorConstructor::~GammaDetectorConstructor()
{}

G4VPhysicalVolume *GammaDetectorConstructor::Construct()
{
    //creating World Volume
    G4NistManager *nist = G4NistManager::Instance();
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

    G4Box *solidWorld = new G4Box("solidWorld", 50*m, 50*m, 50*m);

    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicalWorld");
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "PhysWorld", 0, false, 0, true);
    
    G4VisAttributes *objAttr = new G4VisAttributes(blue);
    objAttr->SetVisibility(true);
    objAttr->SetForceSolid(true);
    G4Material* objectMaterial = nist->FindOrBuildMaterial("G4_WATER");

    GammaSensitive* sensitive = new GammaSensitive("objectDetector");
    G4SDManager* sdMan = G4SDManager::GetSDMpointer();
    sdMan->AddNewDetector(sensitive);

    G4Box *object = new G4Box("Object", 10*m, 10*m, 2.5*m);
    G4LogicalVolume *lv = new G4LogicalVolume(object, objectMaterial, "LogicalObj");
    lv->SetVisAttributes(objAttr);
    lv->SetSensitiveDetector(sensitive);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 10*m), lv, "Object", logicWorld, false, 0);
    
    return physWorld;
}