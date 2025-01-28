#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "tools/colors"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    virtual G4VPhysicalVolume *Construct();
private:
    G4LogicalVolume* logicBorScin;
    G4LogicalVolume* logictargetPol;
    G4LogicalVolume* logictargetAl;
    virtual void ConstructSDandField();
    void SetMaterials();

    G4NistManager *nist = G4NistManager::Instance();
    G4Material *Polyvinyltoluene;
    G4Material* PWO;
    G4Material *BorScinmat;
    G4Material *worldMat;
    G4Material* Al;
    G4Material* Polyetilene;

};

#endif
