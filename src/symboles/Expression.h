#ifndef LUTIN_EXPRESSION_H
#define LUTIN_EXPRESSION_H

#include <TableDesSymboles.h>
#include "Symbole.h"


class Expression : public Symbole {

public:
    Expression() : Symbole(EXPRESSION), dynamique(false) { }

    virtual void afficher() = 0;

    virtual int eval(TableDesSymboles *tablesDesSymboles) = 0;

    virtual void executer(TableDesSymboles *tableDesSymboles) = 0;

    virtual ~Expression() { };

    int identifiantDynamique() {
        if (this->dynamique) {
            return EXPRESSION;
        }
        else {
            return identifiant;
        }
    }

    void setDynamique(bool dynamique) { this->dynamique = dynamique; }

protected:
    Expression(int id) : Symbole(id), dynamique(false) { }

    bool dynamique;
};


#endif //LUTIN_EXPRESSION_H
