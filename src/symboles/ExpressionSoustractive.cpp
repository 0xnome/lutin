#include <easyloggingpp.h>
#include "ExpressionSoustractive.h"

using namespace std;

ExpressionSoustractive::ExpressionSoustractive(Terme *terme, Expression *expression) : Expression(
        EXPRESSION_SOUSTRACTIVE), terme(terme), expression(expression)
{
}

ExpressionSoustractive::~ExpressionSoustractive()
{
    delete this->terme;
    delete this->expression;
}

void ExpressionSoustractive::afficher()
{
    this->expression->afficher();
    cout << "-";
    this->terme->afficher();
}

void ExpressionSoustractive::executer(TableDesSymboles *tableDesSymboles)
{

}

int ExpressionSoustractive::eval(TableDesSymboles *tablesDesSymboles)
{
    LOG(INFO) << "ExpressionSoustractive::eval";
    return (expression->eval(tablesDesSymboles) - terme->eval(tablesDesSymboles));
}

void ExpressionSoustractive::analyser(TableDesSymboles *tableDesSymboles)
{
    this->terme->analyser(tableDesSymboles);
    this->expression->analyser(tableDesSymboles);
}
