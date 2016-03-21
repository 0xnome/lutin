#ifndef LUTIN_INSTRUCTIONLECTURE_H
#define LUTIN_INSTRUCTIONLECTURE_H

#include <TableDesSymboles.h>
#include "BlocInstruction.h"
#include "IdTerminal.h"

class InstructionLecture : public BlocInstruction {
public:
    InstructionLecture(IdTerminal *idTerminal);

    virtual void afficher();

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual bool analyser(TableDesSymboles *tableDesSymboles);

    virtual void optimiser();

    ~InstructionLecture();

    virtual bool estVide();

    virtual void optimiser(TableDesSymboles*);

protected:
    IdTerminal *id;

};


#endif