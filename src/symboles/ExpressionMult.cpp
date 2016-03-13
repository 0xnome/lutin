#include "ExpressionMult.h"

using namespace std;

void ExpressionMult::afficher()
{
    // TODO
}

void ExpressionMult::exectuer()
{
    this->terme->afficher();
    cout<<"*";
    this->facteur->afficher();
}



