#include <easyloggingpp.h>
#include "ExpressionAdditive.h"
#include "ConstanteNumerique.h"

using namespace std;

ExpressionAdditive::ExpressionAdditive(Terme *terme, Expression *expression) : Expression(EXPRESSION_ADDITIVE),
                                                                               terme(terme), expression(expression)
{
}

ExpressionAdditive::~ExpressionAdditive()
{
    delete this->terme;
    delete this->expression;
}

void ExpressionAdditive::afficher()
{
    this->expression->afficher();
    cout << "+";
    this->terme->afficher();
}

int ExpressionAdditive::eval(TableDesSymboles *tablesDesSymboles)
{
    LOG(INFO) << "ExpressionAdditive::eval";
    return (terme->eval(tablesDesSymboles) + expression->eval(tablesDesSymboles));
}


void ExpressionAdditive::executer(TableDesSymboles *tableDesSymboles)
{

}

bool ExpressionAdditive::estConstante(TableDesSymboles *tableDesSymboles)
{
    return this->terme->estConstante(tableDesSymboles) && this->expression->estConstante(tableDesSymboles);
}

bool ExpressionAdditive::analyser(TableDesSymboles *tableDesSymboles, Contexte contexte)
{
    contexte.validerDeclaration = true;
    contexte.validerInitilisation = true;
    return terme->analyser(tableDesSymboles, contexte) && expression->analyser(tableDesSymboles, contexte);
}

void ExpressionAdditive::optimiser(TableDesSymboles *tableDesSymboles)
{
    this->expression->optimiser(tableDesSymboles);
    if (this->expression->estConstante(tableDesSymboles))
    {
        int val = this->expression->eval(tableDesSymboles);
        Expression *expr = new ConstanteNumerique(
                new NumTerminal(val, this->expression->getLigne(), this->expression->getColonne()));
        delete this->expression;
        this->expression = expr;
    }
    this->terme->optimiser(tableDesSymboles);
    if (this->terme->estConstante(tableDesSymboles))
    {
        int val = this->terme->eval(tableDesSymboles);
        Terme *ter = new ConstanteNumerique(new NumTerminal(val, this->terme->getLigne(), this->terme->getColonne()));
        delete this->terme;
        this->terme = ter;
    }
}
