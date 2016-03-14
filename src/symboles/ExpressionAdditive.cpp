#include "ExpressionAdditive.h"

using namespace std;


void ExpressionAdditive::afficher()
{
    this->expression->afficher();
    cout<<"+";
    this->terme->afficher();
}

int ExpressionAdditive::eval(TableDesSymboles *tablesDesSymboles)
{
    return (terme->eval(tablesDesSymboles) + expression->eval(tablesDesSymboles));
}

void ExpressionAdditive::executer(TableDesSymboles *tableDesSymboles)
{

}





