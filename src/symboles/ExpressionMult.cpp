#include "ExpressionMult.h"

using namespace std;

void ExpressionMult::afficher()
{
    this->terme->afficher();
    cout<<"*";
    this->facteur->afficher();
}

int ExpressionMult::eval()
{
    return (facteur->eval() * terme->eval());
}


void ExpressionMult::executer(TableDesSymboles *tableDesSymboles)
{

}


