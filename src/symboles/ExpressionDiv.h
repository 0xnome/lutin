#ifndef LUTIN_EXPRESSIONDIV_H
#define LUTIN_EXPRESSIONDIV_H


#include "Terme.h"
#include "Facteur.h"

class ExpressionDiv : public Terme
{

public:
    ExpressionDiv(Facteur * facteur1, Terme * terme1): Terme(EXPRESSION_DIV)
    {
        this->terme = terme1;
        this->facteur = facteur1;
    }

    void afficher();

    void executer(TableDesSymboles *tableDesSymboles);

    int eval(TableDesSymboles *tablesDesSymboles);

    ~ExpressionDiv()
    {
        delete this->terme;
        delete this->facteur;
    }

protected:

    Terme * terme;

    Facteur * facteur;

};


#endif //LUTIN_EXPRESSIONDIV_H
