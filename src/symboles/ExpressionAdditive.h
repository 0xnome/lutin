#ifndef LUTIN_EXPRESSIONADDITIVE_H
#define LUTIN_EXPRESSIONADDITIVE_H


#include "Expression.h"
#include "Terme.h"

class ExpressionAdditive : public Expression
{

public:
    ExpressionAdditive(Terme *terme1, Expression *expression1) : Expression(EXPRESSION_ADDITIVE)
    {
        this->terme = terme1;
        this->expression = expression1;
    }

    void afficher();
    int eval(TableDesSymboles *tablesDesSymboles);

    void executer(TableDesSymboles *tableDesSymboles);

    ~ExpressionAdditive()
    {
        delete this->terme;
        delete this->expression;
    }


protected:

    Expression *expression;

    Terme *terme;

};


#endif //LUTIN_EXPRESSIONADDITIVE_H
