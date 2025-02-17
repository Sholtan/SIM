#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}


void MyDetectorConstruction::SetMaterials()
{
    Polyvinyltoluene = new G4Material("Polyvinyltoluene", 1.032*g/cm3, 2); // ПЛАСТИКОВЫЙ СЦИНТИЛЛЯТОР
    Polyvinyltoluene->AddElement(nist->FindOrBuildElement("C"), 9);
    Polyvinyltoluene->AddElement(nist->FindOrBuildElement("H"), 10);

/*
    PWO = new G4Material("PWO", 8.29 * g / cm3, 3);
    PWO->AddElement(nist->FindOrBuildElement("P"), 1);
    PWO->AddElement(nist->FindOrBuildElement("O"), 4);
    PWO->AddElement(nist->FindOrBuildElement("W"), 1);
*/

    Pb = new G4Material("Pb", 11.34 * g / cm3, 1);
    Pb->AddElement(nist->FindOrBuildElement("Pb"), 100 * perCent);


// конвертер - Свинец 11,34 гр/см3

// Пластик FscScint   1.032 гр/см3,  C9H10, заметлитель




    /*G4Material* PWO = new G4Material("Wmat", 19.3 * g / cm3, 3);
    PWO->AddElement(nist->FindOrBuildElement("W"), 92.8 * perCent);
    PWO->AddElement(nist->FindOrBuildElement("Ni"), 4.5 * perCent);
    PWO->AddElement(nist->FindOrBuildElement("Cu"), 2.7 * perCent);*/

    BorScinmat = new G4Material("BorScinmat", 1.026 * g / cm3, 3);
    BorScinmat->AddElement(nist->FindOrBuildElement("C"), (86.5301) * perCent);
    BorScinmat->AddElement(nist->FindOrBuildElement("H"), (8.4699) * perCent);
    BorScinmat->AddElement(nist->FindOrBuildElement("B"), (5.0) * perCent);

    //G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");
    worldMat = new G4Material("worldMat", 1.205e-14 * g / cm3, 3);
    worldMat->AddElement(nist->FindOrBuildElement("N"), 75.5 * perCent);
    worldMat->AddElement(nist->FindOrBuildElement("O"), 23.1 * perCent);
    worldMat->AddElement(nist->FindOrBuildElement("Ar"), 1.4 * perCent);



// мишень - Алюминий 40 мм  
// 


    Al = new G4Material("Al", 2.7 * g / cm3, 1);
    Al->AddElement(nist->FindOrBuildElement("Al"), 100 * perCent);

    Polyetilene = new G4Material("Polyetilene", 0.92 * g / cm3, 2); // ПЛАСТИКОВЫЙ СЦИНТИЛЛЯТОР
    Polyetilene->AddElement(nist->FindOrBuildElement("C"), 2);
    Polyetilene->AddElement(nist->FindOrBuildElement("H"), 4);
}


G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    SetMaterials();
    // МИР

    G4Box* solidWorld = new G4Box("solidWorld", 85 * mm, 85 * mm, 300 * mm);
    //G4Box *solidWorld = new G4Box("solidWorld", 180*cm, 180*cm, 300*cm);

    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

    // ПЛАСТИКОВЫЙ СЦИНТИЛЛЯТОР

    G4Box *solidPlasticScin = new G4Box("solidPlasticScin", 60*mm, 60*mm, 0.75*mm);
    G4LogicalVolume *logicPlasticScin = new G4LogicalVolume(solidPlasticScin, Polyvinyltoluene, "logicPlasticScin");

    G4VisAttributes * calTubeVisAtt = new G4VisAttributes(G4Colour(0.,1.,1.)); // Instantiation of a set of visualization attributes with cyan colour
    //calTubeVisAtt->SetForceWireframe(true); // Set the forced wireframe style
    logicPlasticScin->SetVisAttributes(calTubeVisAtt);

    G4VPhysicalVolume *physPlasticScin[109];

    // ВОЛЬФРАМОВЫЙ ПРЕОБРАЗОВАТЕЛЬ
    
    G4Box *solidWolfram = new G4Box("solidWolfram", 60*mm, 60*mm, 0.4*mm);
    G4LogicalVolume *logicWolfram = new G4LogicalVolume(solidWolfram, Pb, "logicWolfram");
    G4VisAttributes * calTubeVisAtt2 = new G4VisAttributes(G4Colour(0.5,0.5,0.5)); // Instantiation of a set of visualization attributes with cyan colour
    //calTubeVisAtt2->SetForceWireframe(true); // Set the forced wireframe style
    logicWolfram->SetVisAttributes(calTubeVisAtt2);

    G4VPhysicalVolume *physWolfram[109];


    for (int i = 0; i < 109; i++) {
        physPlasticScin[i] = new G4PVPlacement(0, G4ThreeVector(0., 0., (-125.+0.75+2.3*i)*mm), logicPlasticScin, "physPlasticScin" + std::to_string(i), logicWorld, false, i, true);
        physWolfram[i] = new G4PVPlacement(0, G4ThreeVector(0., 0., (-123.5+0.4+2.3*i)*mm), logicWolfram, "physWolfram" + std::to_string(i), logicWorld, false, i, true);
    }



    //G4Box* solidend = new G4Box("solidend", 60 * mm, 60 * mm, 0.4 * mm);
    //G4LogicalVolume* logicend = new G4LogicalVolume(solidend, PWO, "logicend");
    //G4VPhysicalVolume* physend = new G4PVPlacement(0, G4ThreeVector(0., 0., (-123.5 + 0.4 + 2.3 * 109) * mm), logicend, "physend", logicWorld, false, 0, true);


// 10 ММ ПЛАСТИК
    G4Box *solid10Plastic = new G4Box("solid10Plastic", 60*mm, 5*mm, 50*mm);
    G4LogicalVolume *logic10Plastic = new G4LogicalVolume(solid10Plastic, Polyvinyltoluene, "logic10Plastic");

    G4VisAttributes * calTubeVisAtt3 = new G4VisAttributes(G4Colour(1.,1.,0.)); // Instantiation of a set of visualization attributes with cyan colour
    //calTubeVisAtt3->SetForceWireframe(true); // Set the forced wireframe style
    logic10Plastic->SetVisAttributes(calTubeVisAtt3);

    G4Box *solidBorScin = new G4Box("solidBorScin", 60.*mm, 2.5*mm, 50.*mm);
    logicBorScin = new G4LogicalVolume(solidBorScin, BorScinmat, "logicBorScin");

    G4VisAttributes * calTubeVisAtt4 = new G4VisAttributes(G4Colour(0.,1.,0.)); // Instantiation of a set of visualization attributes with cyan colour
    //calTubeVisAtt3->SetForceWireframe(true); // Set the forced wireframe style
    logicBorScin->SetVisAttributes(calTubeVisAtt4);
    


    G4VPhysicalVolume *phys10Plastic[9];
    G4VPhysicalVolume *physBorScin[9];

    phys10Plastic[1] = new G4PVPlacement(0, G4ThreeVector(0., 65.*mm, -75.*mm), logic10Plastic, "phys10Plastic0", logicWorld, false, 1, true);
    physBorScin[1] = new G4PVPlacement(0, G4ThreeVector(0., 72.5 * mm, -75. * mm), logicBorScin, "physBorScin0", logicWorld, false, 1, true);
    
    phys10Plastic[5] = new G4PVPlacement(0, G4ThreeVector(0., 65.*mm, 75.7*mm), logic10Plastic, "phys10Plastic1", logicWorld, false, 5, true);
    physBorScin[5] = new G4PVPlacement(0, G4ThreeVector(0., 72.5 *mm, 75.7*mm), logicBorScin, "physBorScin1", logicWorld, false, 5, true);


    phys10Plastic[3] = new G4PVPlacement(0, G4ThreeVector(0., -65.*mm, -75.*mm), logic10Plastic, "phys10Plastic6", logicWorld, false, 3, true);
    physBorScin[3] = new G4PVPlacement(0, G4ThreeVector(0., -72.5 * mm, -75. * mm), logicBorScin, "physBorScin6", logicWorld, false, 3, true);
    
    phys10Plastic[7] = new G4PVPlacement(0, G4ThreeVector(0., -65.*mm, 75.7*mm), logic10Plastic, "phys10Plastic7", logicWorld, false, 7, true);
    physBorScin[7] = new G4PVPlacement(0, G4ThreeVector(0., -72.5 *mm, 75.7*mm), logicBorScin, "physBorScin7", logicWorld, false, 7, true);


    G4RotationMatrix * RotMat = new G4RotationMatrix();
    RotMat -> rotate(90.0 *deg, G4ThreeVector(0., 0., 1.));
    RotMat -> invert();

    phys10Plastic[2] = new G4PVPlacement(RotMat, G4ThreeVector(65. *mm, 0., -75*mm), logic10Plastic, "phys10Plastic2", logicWorld, false, 2, true);
    physBorScin[2] = new G4PVPlacement(RotMat, G4ThreeVector(72.5 * mm, 0., -75 * mm), logicBorScin, "physBorScin2", logicWorld, false, 2, true);
    
    phys10Plastic[6] = new G4PVPlacement(RotMat, G4ThreeVector(65. *mm, 0., 75.7*mm), logic10Plastic, "phys10Plastic3", logicWorld, false, 6, true);
    physBorScin[6] = new G4PVPlacement(RotMat, G4ThreeVector(72.5 *mm, 0., 75.7*mm), logicBorScin, "physBorScin3", logicWorld, false, 6, true);

    phys10Plastic[4] = new G4PVPlacement(RotMat, G4ThreeVector(-65. *mm, 0., -75*mm), logic10Plastic, "phys10Plastic4", logicWorld, false, 4, true);
    physBorScin[4] = new G4PVPlacement(RotMat, G4ThreeVector(-72.5 * mm, 0., -75 * mm), logicBorScin, "physBorScin4", logicWorld, false, 4, true);
    
    phys10Plastic[8] = new G4PVPlacement(RotMat, G4ThreeVector(-65. *mm, 0., 75.7*mm), logic10Plastic, "phys10Plastic5", logicWorld, false, 8, true);
    physBorScin[8] = new G4PVPlacement(RotMat, G4ThreeVector(-72.5 *mm, 0., 75.7*mm), logicBorScin, "physBorScin5", logicWorld, false, 8, true);

    G4RotationMatrix* RotMatface = new G4RotationMatrix();
    RotMatface->rotate(90.0 * deg, G4ThreeVector(1., 0., 0.));
    RotMatface->invert();
    phys10Plastic[0] = new G4PVPlacement(RotMatface, G4ThreeVector(0., 0., -130* mm), logic10Plastic, "phys10Plastic9", logicWorld, false, 0, true);
    physBorScin[0] = new G4PVPlacement(RotMatface, G4ThreeVector(0., 0., -137.5 * mm), logicBorScin, "physBorScin9", logicWorld, false, 0, true);


    // TARGET
    G4Box* solidtargetAl = new G4Box("solidtargetAl", 60 * mm, 60 * mm, 25. * mm);
    logictargetAl = new G4LogicalVolume(solidtargetAl, Al, "logictargetAl");
    //G4Box* solidtargetPol = new G4Box("solidtargetPol", 60 * mm, 60 * mm, 35 * mm);
    //logictargetPol = new G4LogicalVolume(solidtargetPol, Polyetilene, "logictargetPol");
    //G4VPhysicalVolume* phystargetAl = new G4PVPlacement(0, G4ThreeVector(0., 0., -217.5*mm), logictargetAl, "phystargetAl", logicWorld, false, 0, true);
    G4VPhysicalVolume* phystargetAl = new G4PVPlacement(0, G4ThreeVector(0., 0., -175 * mm), logictargetAl, "phystargetAl", logicWorld, false, 0, true);
    //G4VPhysicalVolume* phystargetPol = new G4PVPlacement(0, G4ThreeVector(0., 0., -175 * mm), logictargetPol, "phystargetPol", logicWorld, false, 0, true);
    
    
    
    return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
    MySensitiveDetector* sensDet = new MySensitiveDetector("SensitiveDetector");
    logicBorScin->SetSensitiveDetector(sensDet);




}


