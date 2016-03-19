#ifndef LUTIN_INSTRUCTIONLECTURE_H
#define LUTIN_INSTRUCTIONLECTURE_H

#include <TableDesSymboles.h>
#include "BlocInstruction.h"
#include "IdTerminal.h"

class InstructionLecture : public BlocInstruction {
public:
    InstructionLecture(IdTerminal *idTerminal);

    void afficher();

    void executer(TableDesSymboles *tableDesSymboles);

    virtual void analyser(TableDesSymboles *tableDesSymboles);

    void optimiser();

    ~InstructionLecture();

    bool estVide();

protected:
    IdTerminal *id;

};


#endif