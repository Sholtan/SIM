#include <iostream>

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "tools/colors"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

#include "construction.hh"
//#include "physics.hh"
#include <QBBC.hh>
//#include <FTFP_BERT.hh>
#include <QGSP_BERT_HP.hh>
#include "action.hh"

int main(int argc, char** argv)
{
    for (int i=0; i<argc; i++) {
        G4cout << argv[i] << G4endl;
    }
    G4RunManager *runManager = new G4RunManager();

    runManager->SetUserInitialization(new MyDetectorConstruction());
    //runManager->SetUserInitialization(new MyPhysicsList());
    //runManager->SetUserInitialization(new QGSP_INCLXX);
    //runManager->SetUserInitialization(new FTFP_BERT);
    runManager->SetUserInitialization(new QGSP_BERT_HP);
    runManager->SetUserInitialization(new MyActionInitialization());

    runManager->Initialize();
    runManager->SetPrintProgress(1);
    runManager->BeamOn(100);
    
    /*G4UIExecutive* ui = new G4UIExecutive(argc, argv);

    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();



    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");


    ui->SessionStart();*/
    //UImanager->ApplyCommand(""
    //UImanager->ApplyCommand("/run/BeamOn 100");

    return 0;
}
