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
    
    //G4VisAttributes *objAttr = new G4VisAttributes(blue);
    G4VisAttributes *objAttr = new G4VisAttributes(red);
    objAttr->SetVisibility(true);
    objAttr->SetForceSolid(true);
    G4Material* objectMaterial = nist->FindOrBuildMaterial("G4_WATER");

    GammaSensitive* sensitive = new GammaSensitive("objectDetector");
    G4SDManager* sdMan = G4SDManager::GetSDMpointer();
    sdMan->AddNewDetector(sensitive);

    G4Box *object = new G4Box("Object", 10*m, 10*m, 3.5*cm);
    //G4LogicalVolume *lv = new G4LogicalVolume(object, objectMaterial, "LogicalObj");
    G4LogicalVolume *lv = GammaMakeCement(object);
    lv->SetVisAttributes(objAttr);
    lv->SetSensitiveDetector(sensitive);
    new G4PVPlacement(0, G4ThreeVector(0, 0, 10*m), lv, "Object", logicWorld, false, 0);
    
    return physWorld;
}
G4LogicalVolume *GammaDetectorConstructor::GammaMakeCement(G4Box *object)
{
    G4Element* H = new G4Element("Hydrogen", "H", 1., 1.01 * g / mole);
    G4Element* O = new G4Element("Oxygen", "O", 8., 16.00 * g / mole);
    G4Element* Si = new G4Element("Silicon", "Si", 14., 28.09 * g / mole);
    G4Element* Al = new G4Element("Aluminum", "Al", 13., 26.98 * g / mole);
    G4Element* Ca = new G4Element("Calcium", "Ca", 20., 40.08 * g / mole);
    G4Element* Fe = new G4Element("Iron", "Fe", 26., 55.85 * g / mole);

    G4Material* CaO = new G4Material("Calcium_Oxide", 3.34 * g / cm3, 2);
    CaO->AddElement(Ca, 1);
    CaO->AddElement(O, 1);

    G4Material* SiO2 = new G4Material("Silicon_Dioxide", 2.65 * g / cm3, 2);
    SiO2->AddElement(Si, 1);
    SiO2->AddElement(O, 2);

    G4Material* Al2O3 = new G4Material("Aluminum_Oxide", 3.95 * g / cm3, 2);
    Al2O3->AddElement(Al, 2);
    Al2O3->AddElement(O, 3);

    G4Material* Fe2O3 = new G4Material("Iron_Oxide", 5.24 * g / cm3, 2);
    Fe2O3->AddElement(Fe, 2);
    Fe2O3->AddElement(O, 3);

    G4Material* cement = new G4Material("Cement", 1.80 * g / cm3, 4);

    cement->AddMaterial(CaO, 0.4);
    cement->AddMaterial(SiO2, 0.3);
    cement->AddMaterial(Al2O3, 0.1);
    cement->AddMaterial(Fe2O3, 0.2);
    G4LogicalVolume *lv = new G4LogicalVolume(object, cement, "LogicalObj");

    return lv;
}