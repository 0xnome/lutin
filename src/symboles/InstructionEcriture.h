#ifndef LUTIN_INSTRUCTIONECRITURE_H
#define LUTIN_INSTRUCTIONECRITURE_H

#include "BlocInstruction.h"
#include "Expression.h"

class InstructionEcriture : public BlocInstruction
{
public:
    InstructionEcriture(Expression *exp);

    ~InstructionEcriture();

    virtual void afficher();

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual bool estVide();

    virtual bool analyser(TableDesSymboles *tableDesSymboles, Contexte contexte);

    virtual void optimiser(TableDesSymboles *);

protected:
    Expression *expression;

};


#endif