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
    return (terme->eval(nullptr) + expression->eval(nullptr));
}

void ExpressionAdditive::executer(TableDesSymboles *tableDesSymboles)
{

}





