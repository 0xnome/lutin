#include "ExpressionAdditive.h"

using namespace std;


void ExpressionAdditive::afficher()
{
    this->expression->afficher();
    cout<<"+";
    this->terme->afficher();
}

int ExpressionAdditive::eval()
{
  return 0;
}

void ExpressionAdditive::executer(TableDesSymboles *tableDesSymboles)
{

}





