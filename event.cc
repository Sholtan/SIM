#include "event.hh"

MyEventAction::MyEventAction(MyRunAction*)
{
	wasinelas = 0;
	nF = { {0, {}}, {1, {}}, {2, {}},{3, {}},{4, {}}, };
	nL = { {0, {}}, {1, {}}, {2, {}},{3, {}},{4, {}}, };
	aF = { {0, {}}, {1, {}}, {2, {}},{3, {}},{4, {}},{5, {}}, };
	aL = { {0, {}}, {1, {}}, {2, {}},{3, {}},{4, {}},{5, {}}, };
}
MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
	wasinelas = 0;
	nF = { {0, {}}, {1, {}}, {2, {}},{3, {}},{4, {}}, };
	nL = { {0, {}}, {1, {}}, {2, {}},{3, {}},{4, {}}, };
	aF = { {0, {}}, {1, {}}, {2, {}},{3, {}},{4, {}},{5, {}}, };
	aL = { {0, {}}, {1, {}}, {2, {}},{3, {}},{4, {}},{5, {}}, };
}

void MyEventAction::EndOfEventAction(const G4Event* ev)
{
	G4int n_event = ev->GetEventID();
	//G4cout << "###########################  at the end of THE EVENT TOTAL inelastics: " << wasinelas << " in " << n_event << G4endl;
	G4AnalysisManager* man = G4AnalysisManager::Instance();
	//if (1) {

	G4cout << G4endl << "reactions: " << wasinelas << " , neutrons: " << nF[0].size() << G4endl << G4endl;
	if (wasinelas > 100) { //wasinelas > 100
		int sizenF = nF[0].size();
		int sizenL = nL[0].size();
		int sizeaF = aF[0].size();
		int sizeaL = aL[0].size();
		for (G4int i = 0; i < sizenF; i++) {
			man->FillNtupleDColumn(0, 0, nF[0][i]);
			man->FillNtupleDColumn(0, 1, nF[1][i]);
			man->FillNtupleDColumn(0, 2, nF[2][i]);
			man->FillNtupleDColumn(0, 3, nF[3][i]);
			man->FillNtupleDColumn(0, 4, nF[4][i]);
			man->AddNtupleRow(0);
		}
		for (G4int i = 0; i < sizenL; i++) {
			man->FillNtupleDColumn(1, 0, nL[0][i]);
			man->FillNtupleDColumn(1, 1, nL[1][i]);
			man->FillNtupleDColumn(1, 2, nL[2][i]);
			man->FillNtupleDColumn(1, 3, nL[3][i]);
			man->FillNtupleDColumn(1, 4, nL[4][i]);
			man->AddNtupleRow(1);
		}
		for (G4int i = 0; i < sizeaF; i++) {
			man->FillNtupleDColumn(2, 0, aF[0][i]);
			man->FillNtupleDColumn(2, 1, aF[1][i]);
			man->FillNtupleDColumn(2, 2, aF[2][i]);
			man->FillNtupleDColumn(2, 3, aF[3][i]);
			man->FillNtupleDColumn(2, 4, aF[4][i]);
			man->FillNtupleDColumn(2, 5, aF[5][i]);
			man->AddNtupleRow(2);
		}
		for (G4int i = 0; i < sizeaL; i++) {
			man->FillNtupleDColumn(3, 0, aL[0][i]);
			man->FillNtupleDColumn(3, 1, aL[1][i]);
			man->FillNtupleDColumn(3, 2, aL[2][i]);
			man->FillNtupleDColumn(3, 3, aL[3][i]);
			man->FillNtupleDColumn(3, 4, aL[4][i]);
			man->FillNtupleDColumn(3, 5, aL[5][i]);
			man->AddNtupleRow(3);
		}
		man->FillNtupleIColumn(4, 0, n_event);
		man->AddNtupleRow(4);
	}
}
