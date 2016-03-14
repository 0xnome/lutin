#include "ExpressionDiv.h"


using namespace std;

void ExpressionDiv::afficher()
{
    this->terme->afficher();
    cout<<"/";
    this->facteur->afficher();
}

void ExpressionDiv::executer(TableDesSymboles *tableDesSymboles)
{

}

int ExpressionDiv::eval()
{
return 0;
}
