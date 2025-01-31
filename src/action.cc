#include "action.hh"

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}


void MyActionInitialization::SetPrimaryParticleEnergy(G4double PrimaryParticleEnergy)
{
    fPrimaryParticleEnergy = PrimaryParticleEnergy;
    //G4cout << G4endl << "fPrimaryParticleEnergy in TGFActionInitialization was set to " << fPrimaryParticleEnergy << G4endl << G4endl;
}



void MyActionInitialization::BuildForMaster() const
{
    MyRunAction* runAction = new MyRunAction();
    SetUserAction(runAction);

}

void MyActionInitialization::Build() const
{
    MyPrimaryGenerator* generator = new MyPrimaryGenerator();
    generator->SetPrimaryEnergy(fPrimaryParticleEnergy);
    SetUserAction(generator);

    MyRunAction* runAction = new MyRunAction();
    SetUserAction(runAction);

    MyEventAction* eventAction = new MyEventAction(runAction);
    SetUserAction(eventAction);

    MySteppingAction* steppingAction = new MySteppingAction(eventAction);
    SetUserAction(steppingAction);
}
