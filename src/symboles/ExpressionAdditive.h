#ifndef LUTIN_EXPRESSIONADDITIVE_H
#define LUTIN_EXPRESSIONADDITIVE_H


#include "Expression.h"
#include "Terme.h"

class ExpressionAdditive : public Expression
{

public:
    ExpressionAdditive(Terme *terme1, Expression *expression1);

    ~ExpressionAdditive();


    virtual int eval(TableDesSymboles *tablesDesSymboles);

    virtual void afficher();

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual bool analyser(TableDesSymboles *tableDesSymboles, Contexte contexte);

    virtual bool estConstante(TableDesSymboles *tableDesSymboles);

    virtual void optimiser(TableDesSymboles* tableDesSymboles);

    virtual Expression* simplifier(TableDesSymboles* tableDesSymboles);
protected:

    Terme *terme;

    Expression *expression;

    static const unsigned ELEMENT_NEUTRE = 0;
};


#endif //LUTIN_EXPRESSIONADDITIVE_H
