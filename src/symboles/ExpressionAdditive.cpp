#include "ExpressionAdditive.h"

using namespace std;

ExpressionAdditive::ExpressionAdditive(Terme *terme, Expression *expression) : Expression(EXPRESSION_ADDITIVE),
                                                                               terme(terme), expression(expression) {
}

ExpressionAdditive::~ExpressionAdditive() {
    delete this->terme;
    delete this->expression;
}

void ExpressionAdditive::afficher() {
    this->expression->afficher();
    cout << "+";
    this->terme->afficher();
}

int ExpressionAdditive::eval(TableDesSymboles *tablesDesSymboles) {
    return (terme->eval(tablesDesSymboles) + expression->eval(tablesDesSymboles));
}

void ExpressionAdditive::executer(TableDesSymboles *tableDesSymboles) {

}
