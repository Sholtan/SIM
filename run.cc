#include "run.hh"

MyRunAction::MyRunAction()
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	

	man->CreateH1("fE", "fE", 100, 0.1, 10, "nanosecond", "fenergy");
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