#ifndef LUTIN_EXPRESSIONSOUSTRACTIVE_H
#define LUTIN_EXPRESSIONSOUSTRACTIVE_H


#include "Expression.h"
#include "Terme.h"
#include "IdentificateurFacteur.h"

class ExpressionSoustractive : public Expression
{

public:
    ExpressionSoustractive(Terme *terme, Expression *expression);

    ~ExpressionSoustractive();

    virtual void afficher();

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual bool analyser(TableDesSymboles *tableDesSymboles);

    int eval(TableDesSymboles *tablesDesSymboles);

    virtual bool estConstante(TableDesSymboles *tableDesSymboles);

    virtual void optimiser(TableDesSymboles* tableDesSymboles);

    virtual Expression* simplifier(TableDesSymboles* tableDesSymboles);

protected:
    Terme *terme;

    Expression *expression;

    static const unsigned ELEMENT_NEUTRE = 0;
};


#endif //LUTIN_EXPRESSIONSOUSTRACTIVE_H
