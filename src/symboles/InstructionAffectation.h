#ifndef LUTIN_INSTRUCTIONAFFECTATION_H
#define LUTIN_INSTRUCTIONAFFECTATION_H

#include "BlocInstruction.h"
#include "Expression.h"
#include "IdTerminal.h"

class InstructionAffectation : public BlocInstruction
{
public:
    InstructionAffectation(Expression *expression, IdTerminal *idTerminal);

    ~InstructionAffectation();

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual void afficher();

    virtual bool analyser(TableDesSymboles *tableDesSymboles, Contexte contexte);

    virtual void optimiser(TableDesSymboles *tableDesSymboles);

    virtual bool estVide();

protected:
    Expression *expression;

    IdTerminal *id;
};


#endif