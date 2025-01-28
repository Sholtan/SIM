#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) :
G4VSensitiveDetector(name)
{
	//inelastic = false;
}
MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory*ROhist)
{
	/*G4Track* track = aStep->GetTrack();
	G4VPhysicalVolume *vol = track->GetVolume();
	const G4String volname = vol->GetName();
	G4double globalTime = track->GetGlobalTime();

	const G4ParticleDefinition* particleDefinition = track->GetParticleDefinition();
	const G4String parname = particleDefinition->GetParticleName();*/

	
	//if (volname == "phystargetPol" || volname == "phystargetAl") {
		//if (track->GetTrackID() != 1) {
			//const G4VProcess* creatorProcess = track->GetCreatorProcess();
			//G4cout << parname  << "  was born in  " << creatorProcess->GetProcessName() << "  " << track->GetParentID() << G4endl;
			/*if (creatorProcess->GetProcessName() == "protonInelastic") {
				G4cout << "Time: " << globalTime << "   made inelastic true  " << volname << G4endl;
				G4cout << "Time: " << globalTime << G4endl;
				
			}*/
		//}
	//}
	/*if (volname != "phystargetPol")
	{
		G4cout << inelastic << G4endl;
		if (inelastic == true) {
			G4cout << "after inelastic in  " << volname << G4endl;
		}
	}*/
	/*if (track->GetTrackID() != 1) {
		if (track->GetParentID() == 1)
			G4cout << "parent was primary ";
		G4cout << "Particle is secondary" << G4endl;
		const G4VProcess* creatorProcess = track->GetCreatorProcess();
		G4cout << creatorProcess->GetProcessName() << G4endl;
		//G4cout << creatorProcess->GetProcessName() << G4endl;
	}*/
	//G4StepPoint* preStepPoint = aStep->GetPreStepPoint();
	//G4ThreeVector positionParticle = preStepPoint->GetPosition();
	//G4cout << positionParticle[0] << "  " << positionParticle[1] << "  " << positionParticle[2] << G4endl << G4endl << G4endl;
	
	//G4ProcessType tt = creatorProcess->GetProcessType();
	//G4int itt = tt;
	//creatorProcess->DumpInfo();
	//G4cout << track->GetCreatorProcess()->G4VProcess::GetProcessName();
	
	//G4cout << "something\n" << G4endl << G4endl << G4endl << G4endl;
	/*const G4DynamicParticle* dParticle = track->GetDynamicParticle();
	G4double depositEnergy = aStep->GetTotalEnergyDeposit();
	G4double kinEnergy = dParticle->GetKineticEnergy();
	

	const G4ParticleDefinition* particleDefinition = track->GetParticleDefinition();
	G4int pdg = particleDefinition->GetPDGEncoding();
	G4double globalTime = track->GetGlobalTime();



	G4AnalysisManager* man = G4AnalysisManager::Instance();
	if (pdg == 2112) {
		if (aStep->IsFirstStepInVolume()) {
			man->FillNtupleDColumn(0, 0, depositEnergy / MeV);
			man->FillNtupleDColumn(0, 1, kinEnergy / MeV);
			man->FillNtupleDColumn(0, 2, positionParticle[0]);
			man->FillNtupleDColumn(0, 3, positionParticle[1]);
			man->FillNtupleDColumn(0, 4, positionParticle[2]);
			man->FillNtupleDColumn(0, 5, globalTime / microsecond);
			man->AddNtupleRow(0);
		}
		if (aStep->IsLastStepInVolume()) {
			man->FillNtupleDColumn(1, 0, depositEnergy / MeV);
			man->FillNtupleDColumn(1, 1, kinEnergy / MeV);
			man->FillNtupleDColumn(1, 2, positionParticle[0]);
			man->FillNtupleDColumn(1, 3, positionParticle[1]);
			man->FillNtupleDColumn(1, 4, positionParticle[2]);
			man->FillNtupleDColumn(1, 5, globalTime / microsecond);
			man->AddNtupleRow(1);
		}
	}
	if (pdg == 1000020040) {
		if (aStep->IsFirstStepInVolume()) {
			man->FillNtupleDColumn(2, 0, depositEnergy / MeV);
			man->FillNtupleDColumn(2, 1, kinEnergy / MeV);
			man->FillNtupleDColumn(2, 2, positionParticle[0]);
			man->FillNtupleDColumn(2, 3, positionParticle[1]);
			man->FillNtupleDColumn(2, 4, positionParticle[2]);
			man->FillNtupleDColumn(2, 5, globalTime / microsecond);
			man->AddNtupleRow(2);
		}
		if (aStep->IsLastStepInVolume()) {
			man->FillNtupleDColumn(3, 0, depositEnergy / MeV);
			man->FillNtupleDColumn(3, 1, kinEnergy / MeV);
			man->FillNtupleDColumn(3, 2, positionParticle[0]);
			man->FillNtupleDColumn(3, 3, positionParticle[1]);
			man->FillNtupleDColumn(3, 4, positionParticle[2]);
			man->FillNtupleDColumn(3, 5, globalTime / microsecond);
			man->AddNtupleRow(3);
		}
	}*/

	return true;
}
