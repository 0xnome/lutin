#ifndef LUTIN_EXPRESSIONDIV_H
#define LUTIN_EXPRESSIONDIV_H


#include "Terme.h"
#include "Facteur.h"

class ExpressionDiv : public Terme {

public:
    ExpressionDiv(Facteur *facteur1, Terme *terme1);

    ~ExpressionDiv();

    virtual void afficher();

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual int eval(TableDesSymboles *tablesDesSymboles);

    virtual bool analyser(TableDesSymboles *tableDesSymboles);

    virtual bool estConstante(TableDesSymboles *tableDesSymboles);

    virtual void optimiser(TableDesSymboles *tableDesSymboles);

    virtual Expression *simplifier(TableDesSymboles *tableDesSymboles);

protected:

    Terme *terme;

    Facteur *facteur;

    static const unsigned ELEMENT_NEUTRE = 1;

    static const unsigned ELEMENT_ABSORBANT = 0;
};


#endif //LUTIN_EXPRESSIONDIV_H
