#include "ExpressionDiv.h"


using namespace std;

void ExpressionDiv::afficher()
{
    //TODO
}

void ExpressionDiv::executer()
{
    this->terme->afficher();
    cout<<"/";
    this->facteur->afficher();
}



