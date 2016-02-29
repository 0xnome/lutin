#ifndef LUTIN_BLOCINSTRUCTION_H
#define LUTIN_BLOCINSTRUCTION_H

#include "Symbole.h"
#include "Programme.h"

class BlocInstruction : public Symbole
{
public:
  BlocInstruction();
  ~BlocInstruction();
protected:
  BlocInstruction* suivant;
  Programme* programme;

};


#endif