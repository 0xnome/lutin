#include "AffectationConstante.h"

AffectationConstante::AffectationConstante(IdTerminal* idT, NumTerminal* numT):Symbole(AFFECTATION_CONSTANTE)
{
    id = idT;
    num = numT;
}

AffectationConstante::~AffectationConstante()
{

}
