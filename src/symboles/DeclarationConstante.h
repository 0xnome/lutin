#ifndef LUTIN_DECLARATIONCONSTANTE_H
#define LUTIN_DECLARATIONCONSTANTE_H

#include "BlocDeclaration.h"
#include "AffectationConstante.h"


class DeclarationConstante : public BlocDeclaration
{
public:
  DeclarationConstante(AffectationConstante * affectationConstante);
  ~DeclarationConstante();
    virtual void executer();

    virtual void afficher();

    virtual void analyser();

    virtual void optimiser();

protected:
    AffectationConstante * affectationConstante;

};


#endif