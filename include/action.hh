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

    void SetPrimaryParticleEnergy(G4double);

    
    virtual void Build() const;
    virtual void BuildForMaster() const;

private:
    G4double fPrimaryParticleEnergy;
};

#endif
