#ifndef LUTIN_FACTEUR_H
#define LUTIN_FACTEUR_H


#include "Terme.h"

class ExpressionDiv;
class ExpressionMult;
class Facteur : public Terme
{
protected:
    Facteur(int id) : Terme(id){}
public:
    Facteur():Terme(FACTEUR){}

    ExpressionDiv* expressionDiv;
    ExpressionMult* expressionMult;

    void setExpressionDiv(ExpressionDiv* div);
    void setExpressionMult(ExpressionMult* mult);

};


#endif //LUTIN_FACTEUR_H
