#ifndef LUTIN_EXPRESSIONSOUSTRACTIVE_H
#define LUTIN_EXPRESSIONSOUSTRACTIVE_H


#include "Expression.h"
#include "Terme.h"

class ExpressionSoustractive : public Expression {

public:
    ExpressionSoustractive(Terme *terme, Expression *expression);

    ~ExpressionSoustractive();

    virtual void afficher();

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual void analyser(TableDesSymboles *tableDesSymboles);

    int eval(TableDesSymboles *tablesDesSymboles);

protected:
    Terme *terme;

    Expression *expression;

};


#endif //LUTIN_EXPRESSIONSOUSTRACTIVE_H
