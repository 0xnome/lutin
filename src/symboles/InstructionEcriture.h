#ifndef LUTIN_INSTRUCTIONECRITURE_H
#define LUTIN_INSTRUCTIONECRITURE_H

#include "BlocInstruction.h"

class InstructionEcriture : public BlocInstruction
{
public:
  InstructionEcriture():BlocInstruction(INSTRUCTION_ECRITURE){};
  ~InstructionEcriture(){};

};


#endif