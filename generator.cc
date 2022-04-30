#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
    fParticleGun = new G4ParticleGun(1);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4IonTable* Iontable = particleTable->GetIonTable();
    //G4ParticleDefinition* particle = particleTable->FindParticle(11); // электроны
    //G4ParticleDefinition *particle = particleTable->FindParticle(2212); // протоны 
    //G4ParticleDefinition* particle = Iontable->GetIon(2, 4, 0); // He-4
    //G4ParticleDefinition* particle = Iontable->GetIon(6, 12, 0); // С-12
    //G4ParticleDefinition* particle = Iontable->GetIon(8, 16, 0); // O-16
    G4ParticleDefinition* particle = Iontable->GetIon(26, 56, 0); // Fe-56


    G4ThreeVector pos(0.,0.,-280.*mm);
    G4ThreeVector mom(0.,0.,1.);

    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleEnergy(20.*GeV);

    fParticleGun->GeneratePrimaryVertex(anEvent);

}
