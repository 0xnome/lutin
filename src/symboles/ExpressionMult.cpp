#include "ExpressionMult.h"

using namespace std;

void ExpressionMult::afficher()
{
    this->terme->afficher();
    cout<<"*";
    this->facteur->afficher();
}

int ExpressionMult::eval(TableDesSymboles *tablesDesSymboles)
{
    return (facteur->eval(tablesDesSymboles) * terme->eval(tablesDesSymboles));
}


void ExpressionMult::executer(TableDesSymboles *tableDesSymboles)
{

}


