#include <easyloggingpp.h>
#include "ExpressionSoustractive.h"
#include "ConstanteNumerique.h"

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

bool ExpressionSoustractive::estConstante(TableDesSymboles *tableDesSymboles)
{
    return this->terme->estConstante(tableDesSymboles) && this->expression->estConstante(tableDesSymboles);
}

bool ExpressionSoustractive::analyser(TableDesSymboles *tableDesSymboles, Contexte contexte)
{
    return this->expression->analyser(tableDesSymboles, contexte)
           && this->terme->analyser(tableDesSymboles, contexte);
}

void ExpressionSoustractive::optimiser(TableDesSymboles *tableDesSymboles) {
    this->expression->optimiser(tableDesSymboles);
    if(this->expression->estConstante(tableDesSymboles)){
        int val = this->expression->eval(tableDesSymboles);
        Expression *expr = new ConstanteNumerique(new NumTerminal(val, this->expression->getLigne(), this->expression->getColonne()));
        delete this->expression;
        this->expression = expr;
    }
    this->terme->optimiser(tableDesSymboles);
    if(this->terme->estConstante(tableDesSymboles)){
        int val = this->terme->eval(tableDesSymboles);
        Terme *ter = new ConstanteNumerique(new NumTerminal(val, this->terme->getLigne(), this->terme->getColonne()));
        delete this->terme;
        this->terme = ter;
    }
}
