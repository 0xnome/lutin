#ifndef LUTIN_EXPRESSION_H
#define LUTIN_EXPRESSION_H


#include "Symbole.h"

class Expression : public Symbole
{

public:
    Expression(int id) : Symbole(id)
    { }
};


#endif //LUTIN_EXPRESSION_H
