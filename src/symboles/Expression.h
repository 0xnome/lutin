#ifndef LUTIN_EXPRESSION_H
#define LUTIN_EXPRESSION_H

#include "Symbole.h"

class ExpressionAdditive;
class ExpressionSoustractive;
class ExpressionParenthesee;
class Expression : public Symbole
{

protected:
    Expression(int id) : Symbole(id){ }
public:
    Expression():Symbole(EXPRESSION){}

    ExpressionAdditive* expressionAdditive;
    ExpressionSoustractive* expressionSoustractive;
    ExpressionParenthesee* expressionParenthesee;

    void setExpressionAdditive(ExpressionAdditive* addition);
    void setExpressionSoustractive(ExpressionSoustractive* soustraction);
    void setExpressionParenthesee(ExpressionParenthesee* parenthese);

};


#endif //LUTIN_EXPRESSION_H
