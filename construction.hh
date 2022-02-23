#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4GenericMessenger.hh"

#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    virtual G4VPhysicalVolume *Construct();
    void ConstructCherenkov();
    //void ConstructScintillator();
private:
    virtual void ConstructSDandField();

    G4int nCols, nRows;

    G4Box *solidWorld, *solidRadiator, *solidDetector;

    //G4Tubs *solidScintillator;

    G4LogicalVolume *logicDetector, *logicWorld, *logicRadiator;//, *logicScintillator;
    G4VPhysicalVolume *physWorld, *physRadiator, *physDetector;//, *physScintillator;


    G4GenericMessenger *fMessenger;

    G4Material *SiO2, *H2O, *Aerogel, *worldMat, *NaI;
    G4Element *C, *Na, *I;

    void DefineMaterials();
    


    G4double xWorld, yWorld, zWorld;

    G4bool isCherenkov, isScintillator;

};

#endif
