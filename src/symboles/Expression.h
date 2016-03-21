#ifndef LUTIN_EXPRESSION_H
#define LUTIN_EXPRESSION_H

#include <TableDesSymboles.h>
#include "Symbole.h"


class Expression : public Symbole {

public:
    Expression() : Symbole(EXPRESSION), statiqueClasse(EXPRESSION) { }

    virtual void afficher() = 0;

    virtual int eval(TableDesSymboles *tablesDesSymboles) = 0;

    virtual void executer(TableDesSymboles *tableDesSymboles) = 0;

    virtual void analyser(TableDesSymboles *tableDesSymboles) = 0;

    virtual bool estConstante(TableDesSymboles *tableDesSymboles) = 0;

    virtual ~Expression() { };

    int identifiantStatique() {
        return statiqueClasse;
    }

    void setStatiqueClasse(int statiqueClasse) { this->statiqueClasse = statiqueClasse; }

protected:
    Expression(int id) : Symbole(id), statiqueClasse(id) { }

    int statiqueClasse;
};


#endif //LUTIN_EXPRESSION_H
