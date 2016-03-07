#ifndef LUTIN_EXPRESSIONPARENTHESEE_H
#define LUTIN_EXPRESSIONPARENTHESEE_H

#include "Facteur.h"

class ExpressionParenthesee : public Facteur
{

  protected:
    ExpressionParenthesee(int id) : Facteur(id){}
  public:
    ExpressionParenthesee() : Facteur(EXPRESSION_PARENTHESEE){}
    ~ExpressionParenthesee();
};


#endif //LUTIN_EXPRESSIONPARENTHESEE_H
