#ifndef LUTIN_PROGRAMME_H
#define LUTIN_PROGRAMME_H

#include "BlocDeclaration.h"
#include "BlocInstruction.h"

class Programme : public BlocDeclaration
{
public:
  Programme();
  ~Programme();
protected:
  BlocDeclaration* blocDeclaration;
  BlocInstruction* blocInstruction;
};


#endif