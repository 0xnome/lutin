#ifndef LUTIN_TERME_H
#define LUTIN_TERME_H

#include "TableDesSymboles.h"
#include "Expression.h"

class Terme : public Expression
{

protected:
    Terme(int id) : Expression(id)
    { }

public:
    Terme() : Expression(TERME)
    { }

    virtual void afficher() = 0;

    virtual void executer(TableDesSymboles *tableDesSymboles) = 0;

    virtual int eval(TableDesSymboles *tablesDesSymboles) = 0;

    virtual ~Terme()
    { }

};


#endif //LUTIN_TERME_H
