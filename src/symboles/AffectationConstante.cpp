#include "AffectationConstante.h"


AffectationConstante::AffectationConstante(IdTerminal *idTerminal, NumTerminal* numT):Symbole(AFFECTATION_CONSTANTE)
{
    this->id = idTerminal;
    this->num = numT;
}

void AffectationConstante::setSuivant(AffectationConstante* suiv){
    this->suivant = suiv;

}

AffectationConstante::~AffectationConstante()
{
    delete this->suivant;
    delete this->id;
    delete this->num;
}

AffectationConstante* AffectationConstante::getSuivant() const
{
    return suivant;
}

void AffectationConstante::executer()
{
}

void AffectationConstante::afficher()
{
    this->id->afficher();
    std::cout << "=";
    this->num->afficher();
}

void AffectationConstante::analyser()
{
}

void AffectationConstante::optimiser()
{
}










