#include "actions.hh"
#include "generator.hh"

GammaActionInitialization::GammaActionInitialization()
{}

GammaActionInitialization::~GammaActionInitialization() {}

void GammaActionInitialization::Build() const
{
    GammaPrimaryGen *gen = new GammaPrimaryGen();
    SetUserAction(gen);
}