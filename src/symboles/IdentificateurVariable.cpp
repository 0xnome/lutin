#include "IdentificateurVariable.h"

void IdentificateurVariable::setSuivant(IdentificateurVariable* suiv){
    this->suivant = suiv;
}

void IdentificateurVariable::afficher()
{
    std::cout << this->identifiant;
}

IdentificateurVariable::IdentificateurVariable(IdTerminal *idTerminal1):Symbole(IDENTIFICATEUR_VARIABLE)
{
    this->idTerminal = idTerminal1;
    this->suivant = nullptr;
}


IdentificateurVariable*IdentificateurVariable::getSuivant() const
{
    return suivant;
}

IdentificateurVariable::~IdentificateurVariable()
{
    delete this->idTerminal;
    delete this->suivant;
}

void IdentificateurVariable::executer()
{
    //TODO
}

void IdentificateurVariable::analyser()
{
    //TODO
}

void IdentificateurVariable::optimiser()
{
    //TODO
}








