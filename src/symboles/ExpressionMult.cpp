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
  return 0;
}


void ExpressionMult::executer(TableDesSymboles *tableDesSymboles)
{

}


