#ifndef ACTIONS_HH
#define ACTIONS_HH

#include "G4VUserActionInitialization.hh"

class GammaActionInitialization : public G4VUserActionInitialization
{
public:
    GammaActionInitialization();
    ~GammaActionInitialization();

    virtual void Build() const;
    
};
#endif