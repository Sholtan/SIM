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
#include <FTFP_INCLXX_HP.hh> // almost same results




#include "action.hh"

int main(int argc, char** argv)
{
    
    if (argc != 2)
    {
        G4cout << G4endl << G4endl  << G4endl << "ERROR, MISSING ARGUMENTS! PROVIDE PRIMARY PARTICLE ENERGY AS FIRST VALUE" << G4endl << G4endl << G4endl << G4endl;
        return 1;
    }

    G4double PrimaryParticleEnergy = atof(argv[1]);

    G4MTRunManager* runManager = new G4MTRunManager();
    //G4RunManager *runManager = new G4RunManager();

    runManager->SetUserInitialization(new MyDetectorConstruction());
    //runManager->SetUserInitialization(new MyPhysicsList());
    //runManager->SetUserInitialization(new QGSP_INCLXX);
    //runManager->SetUserInitialization(new FTFP_BERT);
    


    runManager->SetUserInitialization(new QGSP_BERT_HP());
    //runManager->SetUserInitialization(new FTFP_INCLXX_HP());


    //runManager->SetUserInitialization(new MyActionInitialization());
    MyActionInitialization *actionInitialization = new MyActionInitialization();
    actionInitialization->SetPrimaryParticleEnergy(PrimaryParticleEnergy);
    runManager->SetUserInitialization(actionInitialization);


    runManager->SetNumberOfThreads(16);
    G4cout << G4endl << G4endl << "NUMBER THREADS: " << runManager->GetNumberOfThreads() << G4endl<< G4endl;
    runManager->Initialize();
   
    //ui = new G4UIExecutive(argc, argv);
    // for statistics:
    G4UImanager* UI = G4UImanager::GetUIpointer();
    UI->ApplyCommand("/control/execute run.mac");


    //ui->SessionStart();

    //for graphics
    /*
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();
    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/control/execute vis.mac");
    ui->SessionStart();
    delete ui;
    delete visManager;
*/    


    delete runManager;

    return 0;
}
