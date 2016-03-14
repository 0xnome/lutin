//
// Created by HAIDARA Mohamed El Mouctar on 29/02/2016.
//

#ifndef LUTIN_EXPRESSIONMULT_H
#define LUTIN_EXPRESSIONMULT_H

#include "Facteur.h"

class ExpressionMult : public Terme
{

public:
    ExpressionMult(Facteur *facteur1, Terme *terme1) : Terme(EXPRESSION_MULT)
    {
        this->facteur = facteur1;
        this->terme = terme1;
    }

    void executer(TableDesSymboles *tableDesSymboles);

    void afficher();

    int eval(TableDesSymboles *tablesDesSymboles);


    ~ExpressionMult()
    {
        delete this->terme;
        delete this->facteur;
    }

protected:
    Facteur *facteur;

    Terme *terme;
};


#endif //LUTIN_EXPRESSIONMULT_H
