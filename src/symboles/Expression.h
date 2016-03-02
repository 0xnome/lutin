#ifndef LUTIN_EXPRESSION_H
#define LUTIN_EXPRESSION_H


#include "Symbole.h"

class Expression : public Symbole
{

protected:
    Expression(int id) : Symbole(id){ }
public:
    Expression():Symbole(EXPRESSION){}
};


#endif //LUTIN_EXPRESSION_H
