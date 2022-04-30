#include "run.hh"

MyRunAction::MyRunAction()
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->SetNtupleMerging(true);
	man->CreateNtuple("First_step_neutrons", "First_step_neutrons");
	man->CreateNtupleDColumn("kin_E");
	man->CreateNtupleDColumn("x");
	man->CreateNtupleDColumn("y");
	man->CreateNtupleDColumn("z");
	man->CreateNtupleDColumn("t");
	man->FinishNtuple(0);

	man->CreateNtuple("Last_step_neutrons", "Last_step_neutrons");
	man->CreateNtupleDColumn("kin_E");
	man->CreateNtupleDColumn("x");
	man->CreateNtupleDColumn("y");
	man->CreateNtupleDColumn("z");
	man->CreateNtupleDColumn("t");
	man->FinishNtuple(1);

	man->CreateNtuple("First_step_alpha", "First_step_alpha");
	man->CreateNtupleDColumn("deposit_E");
	man->CreateNtupleDColumn("kin_E");
	man->CreateNtupleDColumn("x");
	man->CreateNtupleDColumn("y");
	man->CreateNtupleDColumn("z");
	man->CreateNtupleDColumn("t");
	man->FinishNtuple(2);

	man->CreateNtuple("Last_step_alpha", "Last_step_alpha");
	man->CreateNtupleDColumn("deposit_E");
	man->CreateNtupleDColumn("kin_E");
	man->CreateNtupleDColumn("x");
	man->CreateNtupleDColumn("y");
	man->CreateNtupleDColumn("z");
	man->CreateNtupleDColumn("t");
	man->FinishNtuple(3);

	man->CreateNtuple("events", "events");
	man->CreateNtupleIColumn("n_Event");
	man->FinishNtuple(4);
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
	G4AnalysisManager* man = G4AnalysisManager::Instance();
	G4int runID = run->GetRunID();
	std::stringstream strRunID;
	strRunID << runID;
	man->OpenFile("output" + strRunID.str() + ".root");

}
void MyRunAction::EndOfRunAction(const G4Run*)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->Write();
	man->CloseFile();
}
