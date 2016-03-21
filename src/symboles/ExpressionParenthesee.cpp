#include <easyloggingpp.h>
#include "ExpressionParenthesee.h"
#include "ConstanteNumerique.h"

using namespace std;

ExpressionParenthesee::ExpressionParenthesee(Expression *expression) : Facteur(EXPRESSION_PARENTHESEE),
                                                                       expression(expression)
{
}

ExpressionParenthesee::~ExpressionParenthesee()
{
    delete this->expression;
}

void ExpressionParenthesee::afficher()
{
    std::cout << "(";
    this->expression->afficher();
    std::cout << ")";
}

int ExpressionParenthesee::eval(TableDesSymboles *tablesDesSymboles)
{
    LOG(INFO) << "ExpressionParenthesee::eval";
    return expression->eval(tablesDesSymboles);
}

void ExpressionParenthesee::executer(TableDesSymboles *tableDesSymboles)
{ }


bool ExpressionParenthesee::estConstante(TableDesSymboles *tableDesSymboles) {
    return this->expression->estConstante(tableDesSymboles);
}

void ExpressionParenthesee::optimiser(TableDesSymboles *tableDesSymboles) {
    this->expression->optimiser(tableDesSymboles);
    if(this->expression->estConstante(tableDesSymboles)){
        int val = this->expression->eval(tableDesSymboles);
        Expression *expr = new ConstanteNumerique(new NumTerminal(val, this->expression->getLigne(), this->expression->getColonne()));
        delete this->expression;
        this->expression = expr;
    }
}

bool ExpressionParenthesee::analyser(TableDesSymboles *tableDesSymboles, Contexte contexte)
{
    contexte.validerDeclaration = true;
    contexte.validerInitialisation = true;
    return this->expression->analyser(tableDesSymboles, contexte);
}
