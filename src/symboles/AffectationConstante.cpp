#include "AffectationConstante.h"


AffectationConstante::AffectationConstante(IdTerminal* idT, NumTerminal* numT):Symbole(AFFECTATION_CONSTANTE)
{
    id = idT;
    num = numT;
}

void AffectationConstante::setSuivant(AffectationConstante* suiv){
    this->suivant = suiv;

}

AffectationConstante::~AffectationConstante()
{

}
