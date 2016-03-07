#ifndef LUTIN_AFFECTATIONCONSTANTE_H
#define LUTIN_AFFECTATIONCONSTANTE_H

#include "Symbole.h"
#include "DeclarationConstante.h"
#include "IdTerminal.h"
#include "NumTerminal.h"

class AffectationConstante : public Symbole
{
public:
  AffectationConstante(IdTerminal* id, NumTerminal* num);
  ~AffectationConstante();
protected:
  IdTerminal* id;
  NumTerminal* num;
  AffectationConstante* suivant;
  DeclarationConstante* declarationConstante;
};


#endif
