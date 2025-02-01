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
    
    if (argc != 5)
    {
        G4cout << G4endl << G4endl  << G4endl << "ERROR, MISSING ARGUMENTS! PROVIDE PRIMARY PARTICLE ENERGY AS FIRST VALUE" << G4endl << G4endl << G4endl << G4endl;
        return 1;
    }

    G4double PrimaryParticleEnergy = atof(argv[1]);
    G4int beam_A = atof(argv[2]);;
    G4int beam_charge = atof(argv[3]);;
    G4int phys_list = atof(argv[4]);;



    G4MTRunManager* runManager = new G4MTRunManager();
    //G4RunManager *runManager = new G4RunManager();

    runManager->SetUserInitialization(new MyDetectorConstruction());
    //runManager->SetUserInitialization(new MyPhysicsList());
    //runManager->SetUserInitialization(new QGSP_INCLXX);
    //runManager->SetUserInitialization(new FTFP_BERT);
    


    if (phys_list == 0) 
    {
        runManager->SetUserInitialization(new QGSP_BERT_HP());
        G4cout << "phys_list list is QGSP_BERT_HP" << G4endl;
    }
    else if (phys_list == 1)
    {
        runManager->SetUserInitialization(new FTFP_INCLXX_HP());
        G4cout << "phys_list list is FTFP_INCLXX_HP" << G4endl;
    }
    else
    {
        G4cout << "provide phys_list as 4th argument \n0 for QGSP_BERT_HP \n1 for FTFP_INCLXX_HP" << G4endl;
    }
    


    //runManager->SetUserInitialization(new MyActionInitialization());
    MyActionInitialization *actionInitialization = new MyActionInitialization();
    actionInitialization->SetPrimaryParticleEnergy(PrimaryParticleEnergy, beam_A, beam_charge);
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
