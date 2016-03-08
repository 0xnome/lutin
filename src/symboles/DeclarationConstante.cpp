#include "DeclarationConstante.h"

DeclarationConstante::DeclarationConstante(AffectationConstante *affectationConstante): BlocDeclaration(DECLARATION_CONSTANTE)
{
    this->affectationConstante = affectationConstante;
}

DeclarationConstante::~DeclarationConstante()
{
    delete this->affectationConstante;
}



