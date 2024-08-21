#include <iostream>

#include "G4VUserPhysicsList.hh"
#include "G4RunManager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"

#include "gammaconstruct.hh"
#include "physics.hh"
#include "actions.hh"

int main(int argc, char **argv)
{
    G4RunManager *runManager = new G4RunManager();

    runManager->SetUserInitialization(new GammaDetectorConstructor());
    runManager->SetUserInitialization(new GammaPhysicsList());
    runManager->SetUserInitialization(new GammaActionInitialization());
    runManager->Initialize();

    G4UIExecutive *ui = new G4UIExecutive(argc, argv);
    G4VisManager *vis = new G4VisExecutive();
    vis->Initialize();

    G4UImanager *uman = G4UImanager::GetUIpointer();
    uman->ApplyCommand("/vis/open OGL");
    uman->ApplyCommand("/vis/drawVolume");
    uman->ApplyCommand("/vis/scene/add/trajectories smooth");
    uman->ApplyCommand("/vis/scene/endOfEventAction accumulate");
    ui->SessionStart();

    delete ui;
    delete vis;
    delete runManager;
    
    return 0;
}