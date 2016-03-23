#include <easyloggingpp.h>
#include "ExpressionSoustractive.h"
#include "ConstanteNumerique.h"

using namespace std;

ExpressionSoustractive::ExpressionSoustractive(Terme *terme, Expression *expression) : Expression(
        EXPRESSION_SOUSTRACTIVE, expression->getLigne(), expression->getColonne()), terme(terme), expression(expression)
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

bool ExpressionSoustractive::analyser(TableDesSymboles *tableDesSymboles)
{
    return this->expression->analyser(tableDesSymboles)
           & this->terme->analyser(tableDesSymboles);
}

void ExpressionSoustractive::optimiser(TableDesSymboles *tableDesSymboles)
{
    this->expression->optimiser(tableDesSymboles);
    if (this->expression->estConstante(tableDesSymboles))
    {
        int val = this->expression->eval(tableDesSymboles);
        Expression *expr = new ConstanteNumerique(
                new NumTerminal(val, this->expression->getLigne(), this->expression->getColonne()));
        delete this->expression;
        this->expression = expr;
    }else
    {
        // si on a pu remplacer par une constante numerique on tente une simplification
        Expression *expr;
        expr = (Expression *) this->expression->simplifier(tableDesSymboles);
        if(expr != nullptr)
        {
            delete this->expression;
            this->expression = expr;
        }
    }
    this->terme->optimiser(tableDesSymboles);
    if (this->terme->estConstante(tableDesSymboles))
    {
        int val = this->terme->eval(tableDesSymboles);
        Terme *ter = new ConstanteNumerique(new NumTerminal(val, this->terme->getLigne(), this->terme->getColonne()));
        delete this->terme;
        this->terme = ter;
    }else
    {
        // si on a pu remplacer par une constante numerique on tente une simplification
        Terme *ter;
        ter = (Terme *) this->terme->simplifier(tableDesSymboles);
        if(ter != nullptr)
        {
            delete this->terme;
            this->terme = ter;
        }
    }
}


Expression *ExpressionSoustractive::simplifier(TableDesSymboles* tableDesSymboles) {
    // 0 - a = -a
    /* TODO or not TODO les nombres négatifs that is the question
    if(this->expression->estConstante(tableDesSymboles) && this->expression->eval(tableDesSymboles) == ExpressionSoustractive::ELEMENT_NEUTRE) {
        Expression *exp = (Expression *) this->terme;
        this->terme = nullptr;
        return exp;
    }
        // a - 0 = a
    else */if(this->terme->estConstante(tableDesSymboles) && this->terme->eval(tableDesSymboles) == ExpressionSoustractive::ELEMENT_NEUTRE){
        Expression* exp = this->expression;
        this->expression = nullptr;
        return exp;
    }
    return nullptr;
}
