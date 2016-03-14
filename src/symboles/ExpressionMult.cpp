#include "ExpressionMult.h"

using namespace std;

void ExpressionMult::afficher()
{
    this->terme->afficher();
    cout<<"*";
    this->facteur->afficher();
}

void ExpressionMult::executer(TableDesSymboles *tableDesSymboles)
{

}


