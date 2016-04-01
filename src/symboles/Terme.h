#ifndef LUTIN_TERME_H
#define LUTIN_TERME_H

#include "TableDesSymboles.h"
#include "Expression.h"

class Terme : public Expression {

public:
    Terme() : Expression(TERME, this->ligne, this->colonne) { }

    virtual void afficher() = 0;

    virtual void executer(TableDesSymboles *tableDesSymboles) = 0;

    virtual int eval(TableDesSymboles *tablesDesSymboles) = 0;

    virtual bool estConstante(TableDesSymboles *tableDesSymboles) = 0;

    virtual ~Terme() { }

protected:
    Terme(int id, unsigned ligne, unsigned colonne) : Expression(id, ligne, colonne) { }

};


#endif //LUTIN_TERME_H
