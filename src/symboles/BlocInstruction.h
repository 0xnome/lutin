#ifndef LUTIN_BLOCINSTRUCTION_H
#define LUTIN_BLOCINSTRUCTION_H

#include "Symbole.h"

class BlocInstruction : public Symbole
{
public:
  BlocInstruction();
  ~BlocInstruction();
protected:
  BlocInstruction* suivant;
};


#endif