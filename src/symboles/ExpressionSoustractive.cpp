#include "ExpressionSoustractive.h"

using namespace std;

ExpressionSoustractive::ExpressionSoustractive(Terme *terme, Expression *expression) : Expression(
        EXPRESSION_SOUSTRACTIVE), terme(terme), expression(expression) {
}

ExpressionSoustractive::~ExpressionSoustractive() {
    delete this->terme;
    delete this->expression;
}

void ExpressionSoustractive::afficher() {
    this->expression->afficher();
    cout << "-";
    this->terme->afficher();
}

void ExpressionSoustractive::executer(TableDesSymboles *tableDesSymboles) {

}

int ExpressionSoustractive::eval(TableDesSymboles *tablesDesSymboles) {
    return (terme->eval(tablesDesSymboles) - expression->eval(tablesDesSymboles));
}
