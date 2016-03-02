//
// Created by HAIDARA Mohamed El Mouctar on 29/02/2016.
//

#ifndef LUTIN_TERME_H
#define LUTIN_TERME_H


#include "Expression.h"

class Terme : public Expression
{

protected:
    Terme(int id) : Expression(id){ }
public:
    Terme(): Expression(TERME){}
};


#endif //LUTIN_TERME_H
