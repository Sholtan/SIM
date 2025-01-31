#include "run.hh"

MyRunAction::MyRunAction()
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->SetNtupleMerging(true);
	man->CreateNtuple("steps_info", "steps_info");
	man->CreateNtupleIColumn("Event_id");
	man->CreateNtupleDColumn("Deposite_Energy_MeV");
	man->CreateNtupleDColumn("time_ns");
	man->CreateNtupleIColumn("pdg");
	man->FinishNtuple(0);


	man->CreateNtuple("alpha_born", "alpha_born");
	man->CreateNtupleIColumn("Event_id");
	man->CreateNtupleDColumn("Deposite_Energy_MeV");
	man->CreateNtupleDColumn("time_ns");
	man->FinishNtuple(1);
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
