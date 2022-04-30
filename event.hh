#ifndef EVENT_HH
#define EVENT_HH


#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"
#include "run.hh"

class MyEventAction : public G4UserEventAction
{
public:
	MyEventAction(MyRunAction*);
	~MyEventAction();

	virtual void BeginOfEventAction(const G4Event*);
	virtual void EndOfEventAction(const G4Event*);

	void Addinelas() { wasinelas += 1; }
	std::map<int, std::vector<double>> nF;
	std::map<int, std::vector<double>> nL;
	std::map<int, std::vector<double>> aF;
	std::map<int, std::vector<double>> aL;
	
private:
	G4int wasinelas;

};
#endif