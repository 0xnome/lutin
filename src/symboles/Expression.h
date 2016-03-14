#ifndef LUTIN_EXPRESSION_H
#define LUTIN_EXPRESSION_H

#include <TableDesSymboles.h>
#include "Symbole.h"


class Expression : public Symbole {

public:
    Expression() : Symbole(EXPRESSION) { }

    virtual void afficher() = 0;

    virtual int eval(TableDesSymboles *tablesDesSymboles) = 0;

    virtual void executer(TableDesSymboles *tableDesSymboles) = 0;

    virtual ~Expression() { };

protected:
    Expression(int id) : Symbole(id) { }

};


#endif //LUTIN_EXPRESSION_H
