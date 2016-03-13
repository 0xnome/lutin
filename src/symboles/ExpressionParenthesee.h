#ifndef LUTIN_EXPRESSIONPARENTHESEE_H
#define LUTIN_EXPRESSIONPARENTHESEE_H

#include "Facteur.h"

class ExpressionParenthesee : public Facteur
{

public:
    ExpressionParenthesee(Expression * expression1) : Facteur(EXPRESSION_PARENTHESEE)
    {
        this->expression = expression1;
    }

    void afficher()
    {
        std::cout<<"(";
        this->expression->afficher();
        std::cout<<")";
    }

    ~ExpressionParenthesee()
    {
        delete this->expression;
    }

protected:
    Expression * expression;
};


#endif //LUTIN_EXPRESSIONPARENTHESEE_H
