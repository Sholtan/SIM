#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) :
G4VSensitiveDetector(name)
{}
MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory*ROhist)
{
	G4Track* track = aStep->GetTrack();
	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

	//track->SetTrackStatus(fStopAndKill); should track be killed???

	G4ThreeVector positionParticle = preStepPoint->GetPosition();
	const G4ParticleDefinition* particleDefinition = track->GetParticleDefinition();
	const G4String& particleName = particleDefinition->GetParticleName();
	G4int pdg = particleDefinition->GetPDGEncoding();
	const G4VTouchable* touchable = aStep->GetPreStepPoint()->GetTouchable();
	G4int copyNo = touchable->GetCopyNumber();
	G4double globalTime = track->GetGlobalTime();

	const G4DynamicParticle* dParticle = track->GetDynamicParticle();
	G4double particleEnergy = dParticle->GetTotalEnergy();

	//G4cout << "The Particle NAME: " << particleName << " with PDG = " << pdg << G4endl;
	//G4cout << "some particle position: " << positionParticle << G4endl;

	//G4cout << "copy number " << copyNo << G4endl;


	G4cout << particleName << " time: " << globalTime << ", energy: " << particleEnergy << " no kill" << G4endl;

	G4AnalysisManager* man = G4AnalysisManager::Instance();
	man->FillH1(0, globalTime, particleEnergy);

	return true;
}