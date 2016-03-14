#ifndef LUTIN_EXPRESSIONPARENTHESEE_H
#define LUTIN_EXPRESSIONPARENTHESEE_H

#include "Facteur.h"

class ExpressionParenthesee : public Facteur
{

public:
    ExpressionParenthesee(Expression * expression);

    ~ExpressionParenthesee();

    void afficher();

    int eval(TableDesSymboles *tablesDesSymboles);

protected:
    Expression * expression;
};


#endif //LUTIN_EXPRESSIONPARENTHESEE_H
