#ifndef LUTIN_INSTRUCTIONLECTURE_H
#define LUTIN_INSTRUCTIONLECTURE_H

#include <TableDesSymboles.h>
#include "BlocInstruction.h"
#include "IdTerminal.h"

class InstructionLecture : public BlocInstruction
{
public:
    InstructionLecture(IdTerminal *idTerminal) : BlocInstruction(INSTRUCTION_LECTURE)
    {
        this->id = idTerminal;
    }

    void afficher();

    void executer(TableDesSymboles *tableDesSymboles);

    ~InstructionLecture()
    {
        delete this->id;
    }

protected:
    IdTerminal *id;

};


#endif