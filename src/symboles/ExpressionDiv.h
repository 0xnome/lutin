#ifndef LUTIN_EXPRESSIONDIV_H
#define LUTIN_EXPRESSIONDIV_H


#include "Terme.h"
#include "Facteur.h"

class ExpressionDiv : public Terme
{

public:
    ExpressionDiv(Facteur * facteur1, Terme * terme1);

    ~ExpressionDiv();

    void afficher();

    void executer(TableDesSymboles *tableDesSymboles);

    int eval(TableDesSymboles *tablesDesSymboles);

protected:

    Terme * terme;

    Facteur * facteur;

};


#endif //LUTIN_EXPRESSIONDIV_H
