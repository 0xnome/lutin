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

    void executer(TableDesSymboles *tableDesSymboles);

    void afficher();

    ~InstructionAffectation()
    {
        delete this->expression;
        delete this->id;
    }

protected:
    Expression *expression;

    IdTerminal *id;
};


#endif