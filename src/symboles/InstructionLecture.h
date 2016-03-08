#ifndef LUTIN_INSTRUCTIONLECTURE_H
#define LUTIN_INSTRUCTIONLECTURE_H

#include "BlocInstruction.h"

class InstructionLecture : public BlocInstruction
{
public:
  InstructionLecture():BlocInstruction(INSTRUCTION_LECTURE){};
  ~InstructionLecture(){};

};


#endif