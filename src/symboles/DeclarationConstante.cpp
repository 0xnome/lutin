#include "DeclarationConstante.h"

DeclarationConstante::DeclarationConstante(AffectationConstante *affectationConstante): BlocDeclaration(DECLARATION_CONSTANTE)
{
    this->affectationConstante = affectationConstante;
}

DeclarationConstante::~DeclarationConstante()
{
    delete this->affectationConstante;
}


void DeclarationConstante::executer() {
    //TODO
}

void DeclarationConstante::afficher() {
//TODO
}

void DeclarationConstante::analyser() {
    //TODO
}

void DeclarationConstante::optimiser() {
    //TODO
}
