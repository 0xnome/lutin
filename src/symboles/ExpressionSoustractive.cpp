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
    return (terme->eval(nullptr) - expression->eval(nullptr));
}



