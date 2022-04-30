#include "stepping.hh"


MySteppingAction::MySteppingAction(MyEventAction* eventAction)
{
	fEventAction = eventAction;
}

MySteppingAction::~MySteppingAction()
{}

void MySteppingAction::UserSteppingAction(const G4Step* aStep)
{
	G4Track* track = aStep->GetTrack();
	G4VPhysicalVolume* vol = track->GetVolume();
	const G4String volname = vol->GetLogicalVolume()->GetName();

	const G4ParticleDefinition* particleDefinition = track->GetParticleDefinition();
	G4double pdgcharge = particleDefinition->GetPDGCharge();
	G4int pdg = particleDefinition->GetPDGEncoding();
	const G4String& particlename = particleDefinition->GetParticleName();
	G4double globalTime = track->GetGlobalTime();

	const G4DynamicParticle* dParticle = track->GetDynamicParticle();
	G4double depositEnergy = aStep->GetTotalEnergyDeposit();
	G4double kinEnergy = dParticle->GetKineticEnergy();

	G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
	G4ThreeVector positionParticle = preStepPoint->GetPosition();

	G4int CurrentStepNumber = track->GetCurrentStepNumber();

	//if (track->GetTrackID() == 1) {
		//G4cout << "name: " << particlename << " , charge: " << pdgcharge << " , time: " << globalTime << " , energy: " << kinEnergy << G4endl;
		//G4cout << "name: " << particlename << " , charge: " << pdgcharge << " , time: " << globalTime << " , energy: " << kinEnergy << " , isfirststep: " << aStep->IsFirstStepInVolume() << " , isLast: " << aStep->IsLastStepInVolume() << ", sTEPNUMBER: " << track->GetCurrentStepNumber() << G4endl;
	//}



	if (track->GetTrackID() != 1  && pdgcharge != 0 && CurrentStepNumber < 2) {
		//G4cout << "name: " << particlename << " , charge: " << pdgcharge << " , time: " << globalTime << " , energy: " << kinEnergy << " , isfirststep: " << aStep->IsFirstStepInVolume() << G4endl;
		const G4VProcess* creatorProcess = track->GetCreatorProcess();
		G4String pname = creatorProcess->GetProcessName();
		//if (pname != "phot" && pname != "compt")
		if (particlename != "e-" && particlename != "e+") {
			//G4cout << "name: " << particlename << " , charge: " << pdgcharge << " , time: " << globalTime << " , energy: " << kinEnergy << " , isfirststep: " << aStep->IsFirstStepInVolume() << " , isLast: " << aStep->IsLastStepInVolume() << ", sTEPNUMBER: " << track->GetCurrentStepNumber() << ", process: " << pname << G4endl;
			fEventAction->Addinelas();
		}
	}







	/*if (volname == "phystargetPol" || volname == "phystargetAl") {
		if (track->GetTrackID() != 1) {
			const G4VProcess* creatorProcess = track->GetCreatorProcess();
			G4String pname = creatorProcess->GetProcessName();
			G4cout << "pname: " << pname << G4endl;
			if (pname == "protonInelastic") { // neutronInelastic
				fEventAction->Addinelas();
			}
		}
	}*/
	// && volname == "logicBorScin"



	if (volname == "logicBorScin") {
		if (pdg == 2112) {
			if (aStep->IsFirstStepInVolume()) {
				fEventAction->nF[0].push_back(kinEnergy / MeV);
				fEventAction->nF[1].push_back(positionParticle[0]);
				fEventAction->nF[2].push_back(positionParticle[1]);
				fEventAction->nF[3].push_back(positionParticle[2]);
				fEventAction->nF[4].push_back(globalTime / microsecond);
			}
			if (aStep->IsLastStepInVolume()) {
				fEventAction->nL[0].push_back(kinEnergy / MeV);
				fEventAction->nL[1].push_back(positionParticle[0]);
				fEventAction->nL[2].push_back(positionParticle[1]);
				fEventAction->nL[3].push_back(positionParticle[2]);
				fEventAction->nL[4].push_back(globalTime / microsecond);
			}
		}
		if (pdg == 1000020040) {
			if (aStep->IsFirstStepInVolume()) {

				fEventAction->aF[0].push_back(depositEnergy / MeV);
				fEventAction->aF[1].push_back(kinEnergy / MeV);
				fEventAction->aF[2].push_back(positionParticle[0]);
				fEventAction->aF[3].push_back(positionParticle[1]);
				fEventAction->aF[4].push_back(positionParticle[2]);
				fEventAction->aF[5].push_back(globalTime / microsecond);
			}
			if (aStep->IsLastStepInVolume()) {
				fEventAction->aL[0].push_back(depositEnergy / MeV);
				fEventAction->aL[1].push_back(kinEnergy / MeV);
				fEventAction->aL[2].push_back(positionParticle[0]);
				fEventAction->aL[3].push_back(positionParticle[1]);
				fEventAction->aL[4].push_back(positionParticle[2]);
				fEventAction->aL[5].push_back(globalTime / microsecond);
			}
		}
	}

}

