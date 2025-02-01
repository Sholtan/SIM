#include "action.hh"

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}


void MyActionInitialization::SetPrimaryParticleEnergy(G4double PrimaryParticleEnergy, G4int beam_A, G4int beam_charge)
{
    fPrimaryParticleEnergy = PrimaryParticleEnergy;
    //G4cout << G4endl << "fPrimaryParticleEnergy in TGFActionInitialization was set to " << fPrimaryParticleEnergy << G4endl << G4endl;

    fbeam_A = beam_A;
    fbeam_charge = beam_charge;
}



void MyActionInitialization::BuildForMaster() const
{
    MyRunAction* runAction = new MyRunAction();
    SetUserAction(runAction);

}

void MyActionInitialization::Build() const
{
    MyPrimaryGenerator* generator = new MyPrimaryGenerator();
    generator->SetPrimaryEnergy(fPrimaryParticleEnergy, fbeam_A, fbeam_charge);
    SetUserAction(generator);

    MyRunAction* runAction = new MyRunAction();
    SetUserAction(runAction);

    MyEventAction* eventAction = new MyEventAction(runAction);
    SetUserAction(eventAction);

    MySteppingAction* steppingAction = new MySteppingAction(eventAction);
    SetUserAction(steppingAction);
}
