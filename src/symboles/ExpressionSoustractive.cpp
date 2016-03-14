#include "ExpressionSoustractive.h"

using namespace std;

void ExpressionSoustractive::afficher()
{
    this->expression->afficher();
    cout<<"-";
    this->terme->afficher();
}

void ExpressionSoustractive::executer(TableDesSymboles *tableDesSymboles)
{

}

int ExpressionSoustractive::eval(TableDesSymboles *tablesDesSymboles)
{
    return (terme->eval(tablesDesSymboles) - expression->eval(tablesDesSymboles));
}



