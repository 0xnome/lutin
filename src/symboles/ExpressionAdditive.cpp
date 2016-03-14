#include "ExpressionAdditive.h"

using namespace std;



void ExpressionAdditive::afficher()
{
    this->expression->afficher();
    cout<<"+";
    this->terme->afficher();
}

void ExpressionAdditive::executer(TableDesSymboles *tableDesSymboles)
{

}





