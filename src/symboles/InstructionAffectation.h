#ifndef LUTIN_INSTRUCTIONAFFECTATION_H
#define LUTIN_INSTRUCTIONAFFECTATION_H

#include "BlocInstruction.h"
#include "Expression.h"
#include "IdTerminal.h"

class InstructionAffectation : public BlocInstruction
{
public:
    InstructionAffectation(Expression *expression1, IdTerminal *terminal) : BlocInstruction(INSTRUCTION_AFFECTATION)
    {
        this->expression = expression1;
        this->id = terminal;
    };

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual void afficher();

    ~InstructionAffectation();

    virtual void analyser();

    virtual void optimiser();

    virtual bool estVide();
protected:
    Expression *expression;

    IdTerminal *id;
};


#endif