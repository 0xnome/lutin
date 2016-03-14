#ifndef LUTIN_INSTRUCTIONECRITURE_H
#define LUTIN_INSTRUCTIONECRITURE_H

#include "BlocInstruction.h"
#include "Expression.h"

class InstructionEcriture : public BlocInstruction
{
public:
    InstructionEcriture(Expression *exp) : BlocInstruction(INSTRUCTION_ECRITURE)
    {
        this->expression = exp;
    }

    void afficher();

    void executer(TableDesSymboles *tableDesSymboles);

    ~InstructionEcriture()
    {
        delete this->expression;
    }


protected:
    Expression *expression;

};


#endif