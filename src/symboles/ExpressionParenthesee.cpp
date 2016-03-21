#include <easyloggingpp.h>
#include "ExpressionParenthesee.h"

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

void ExpressionParenthesee::analyser(TableDesSymboles *tableDesSymboles)
{
    this->expression->analyser(tableDesSymboles, (Contexte()));
}

bool ExpressionParenthesee::estConstante(TableDesSymboles *tableDesSymboles) {
    return this->expression->estConstante(tableDesSymboles);
}
