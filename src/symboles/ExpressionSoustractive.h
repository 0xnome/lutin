#ifndef LUTIN_EXPRESSIONSOUSTRACTIVE_H
#define LUTIN_EXPRESSIONSOUSTRACTIVE_H


#include "Expression.h"
#include "Terme.h"

class ExpressionSoustractive : public Expression {

public:
    ExpressionSoustractive(Terme *terme, Expression *expression);

    ~ExpressionSoustractive();

    void afficher();

    void executer(TableDesSymboles *tableDesSymboles);

    int eval(TableDesSymboles *tablesDesSymboles);

protected:
    Terme *terme;

    Expression *expression;

};


#endif //LUTIN_EXPRESSIONSOUSTRACTIVE_H
