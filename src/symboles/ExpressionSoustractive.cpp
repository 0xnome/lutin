#include "ExpressionSoustractive.h"

using namespace std;

void ExpressionSoustractive::afficher()
{
  //TODO
}

void ExpressionSoustractive::exectuer()
{
    this->expression->afficher();
    cout<<"-";
    this->terme->afficher();
}



