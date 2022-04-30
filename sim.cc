#include <iostream>

#include "G4MTRunManager.hh"
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
//#include <QBBC.hh>





#include <QGSP_BERT_HP.hh>
//#include <FTFP_INCLXX_HP.hh> // almost same results




#include "action.hh"

int main(int argc, char** argv)
{
    //G4UIExecutive* ui = 0;
    for (int i=0; i<argc; i++) {
        G4cout << argv[i] << G4endl;
    }
    G4MTRunManager* runManager = new G4MTRunManager();
    //G4RunManager *runManager = new G4RunManager();

    runManager->SetUserInitialization(new MyDetectorConstruction());
    //runManager->SetUserInitialization(new MyPhysicsList());
    //runManager->SetUserInitialization(new QGSP_INCLXX);
    //runManager->SetUserInitialization(new FTFP_BERT);
    


    runManager->SetUserInitialization(new QGSP_BERT_HP());
    //runManager->SetUserInitialization(new FTFP_INCLXX_HP());


    runManager->SetUserInitialization(new MyActionInitialization());
    
    runManager->SetNumberOfThreads(12);
    runManager->Initialize();
   
    //ui = new G4UIExecutive(argc, argv);
     // for statistics:
    //G4UImanager* UI = G4UImanager::GetUIpointer();
    //UI->ApplyCommand("/control/execute run.mac");


    //ui->SessionStart();

    //for graphics
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);

    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();



    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");


    ui->SessionStart();

    return 0;
}
