#include "event.hh"

MyEventAction::MyEventAction(MyRunAction*)
{
    fSteps_info = { {0, {}}, {1, {}}, {2, {}}, {3, {}},};
    falpha_info = { {0, {}}, {1, {}}, {2, {}},};
}
MyEventAction::~MyEventAction()
{
    fSteps_info = { {0, {}}, {1, {}}, {2, {}}, {3, {}},};
    falpha_info = { {0, {}}, {1, {}}, {2, {}},};
}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
}

void MyEventAction::EndOfEventAction(const G4Event* ev)
{
	G4int n_event = ev->GetEventID();
	G4AnalysisManager* man = G4AnalysisManager::Instance();
	G4cout << "END OF EVENT: " << n_event << G4endl;

	int Steps_info_size = fSteps_info[0].size();
    for (G4int i = 0; i < Steps_info_size; i++)
    {
        man->FillNtupleIColumn(0, 0, n_event);     
        man->FillNtupleDColumn(0, 1, fSteps_info[0][i]);     
	    man->FillNtupleDColumn(0, 2, fSteps_info[1][i]);
	    man->FillNtupleIColumn(0, 3, fSteps_info[2][i]);
        man->AddNtupleRow(0);
    }

    int alpha_info_size = falpha_info[0].size();
    for (G4int i = 0; i < alpha_info_size; i++)
    {
        man->FillNtupleIColumn(1, 0, n_event);     
        man->FillNtupleDColumn(1, 1, falpha_info[0][i]);     
	    man->FillNtupleDColumn(1, 2, falpha_info[1][i]);
        man->AddNtupleRow(1);
    }

}
