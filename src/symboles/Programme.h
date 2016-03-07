#ifndef LUTIN_PROGRAMME_H
#define LUTIN_PROGRAMME_H

#include "BlocDeclaration.h"
#include "BlocInstruction.h"
#include "Symbole.h"

class Programme : public Symbole
{
public:
  Programme();
  ~Programme();

  void setBlockInstruction(BlocInstruction* instruction);
  void setBlocDeclaration(BlocDeclaration* declaration);
protected:
  BlocDeclaration* blocDeclaration;
  BlocInstruction* blocInstruction;
};


#endif