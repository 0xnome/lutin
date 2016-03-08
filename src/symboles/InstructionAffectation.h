#ifndef LUTIN_INSTRUCTIONAFFECTATION_H
#define LUTIN_INSTRUCTIONAFFECTATION_H

#include "BlocInstruction.h"

class InstructionAffectation : public BlocInstruction
{
public:
  InstructionAffectation():BlocInstruction(INSTRUCTION_AFFECTATION){};
  ~InstructionAffectation(){};

};


#endif