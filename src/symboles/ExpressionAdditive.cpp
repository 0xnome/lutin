#include "ExpressionAdditive.h"

using namespace std;

void ExpressionAdditive::executer()
{
  //TODO
}

void ExpressionAdditive::afficher()
{
    this->expression->afficher();
    cout<<"+";
    this->terme->afficher();
}



