#ifndef LUTIN_TERME_H
#define LUTIN_TERME_H

#include "Expression.h"

class ExpressionSoustractive;
class ExpressionAdditive;
class ExpressionMult;
class ExpressionDiv;

class Terme : public Expression
{

protected:
    Terme(int id) : Expression(id){ }
public:
    Terme(): Expression(TERME){}
    ExpressionSoustractive* expressionSoustractive;
    ExpressionAdditive* expressionAdditive;
    ExpressionMult* expressionMult;
    ExpressionDiv* expressionDiv;

};


#endif //LUTIN_TERME_H
