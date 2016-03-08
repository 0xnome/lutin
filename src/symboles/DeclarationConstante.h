#ifndef LUTIN_DECLARATIONCONSTANTE_H
#define LUTIN_DECLARATIONCONSTANTE_H

#include "BlocDeclaration.h"
#include "AffectationConstante.h"


class DeclarationConstante : public BlocDeclaration
{
public:
  DeclarationConstante(AffectationConstante * affectationConstante);
  ~DeclarationConstante();

protected:
    AffectationConstante * affectationConstante;

};


#endif