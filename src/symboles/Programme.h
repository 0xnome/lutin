#ifndef LUTIN_PROGRAMME_H
#define LUTIN_PROGRAMME_H

#include "BlocDeclaration.h"
#include "BlocInstruction.h"
#include "Symbole.h"

class Programme : public Symbole
{
public:
  Programme(BlocDeclaration* blocDeclaration, BlocInstruction* blocInstruction);
  ~Programme();
protected:
  BlocDeclaration* blocDeclaration;
  BlocInstruction* blocInstruction;
};


#endif