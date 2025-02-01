#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh"

#include "generator.hh"
#include "run.hh"
#include "event.hh"
#include "stepping.hh"

class MyActionInitialization : public G4VUserActionInitialization
{
public:
    MyActionInitialization();
    ~MyActionInitialization();

    void SetPrimaryParticleEnergy(G4double, G4int, G4int);

    
    virtual void Build() const;
    virtual void BuildForMaster() const;

private:
    G4double fPrimaryParticleEnergy;
    G4int fbeam_A;
    G4int fbeam_charge;
};

#endif
