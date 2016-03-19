#ifndef LUTIN_INSTRUCTIONECRITURE_H
#define LUTIN_INSTRUCTIONECRITURE_H

#include "BlocInstruction.h"
#include "Expression.h"

class InstructionEcriture : public BlocInstruction
{
public:
    InstructionEcriture(Expression *exp);

    ~InstructionEcriture();

    void afficher();

    void executer(TableDesSymboles *tableDesSymboles);

    bool estVide();

    void analyser(TableDesSymboles *tableDesSymboles);

    void optimiser();
protected:
    Expression *expression;

};


#endif