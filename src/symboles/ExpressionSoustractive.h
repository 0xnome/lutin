#ifndef LUTIN_EXPRESSIONSOUSTRACTIVE_H
#define LUTIN_EXPRESSIONSOUSTRACTIVE_H


#include "Expression.h"
#include "Terme.h"

class ExpressionSoustractive : public Expression
{

public:
    ExpressionSoustractive(Terme *terme1, Expression *expression1) : Expression(EXPRESSION_SOUSTRACTIVE)
    {
        this->terme = terme1;
        this->expression = expression1;
    }

    void afficher();

    void executer(TableDesSymboles *tableDesSymboles);

    ~ExpressionSoustractive()
    {
        delete this->terme;
        delete this->expression;
    }

protected:
    Terme *terme;

    Expression *expression;

};


#endif //LUTIN_EXPRESSIONSOUSTRACTIVE_H
