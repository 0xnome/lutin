#include <easyloggingpp.h>
#include "ExpressionParenthesee.h"
#include "ConstanteNumerique.h"

using namespace std;

ExpressionParenthesee::ExpressionParenthesee(Expression *expression) : Facteur(EXPRESSION_PARENTHESEE,
                                                                               expression->getLigne(),
                                                                               expression->getColonne()),
                                                                       expression(expression) {
}

ExpressionParenthesee::~ExpressionParenthesee() {
    delete this->expression;
}

void ExpressionParenthesee::afficher() {
    std::cout << "(";
    this->expression->afficher();
    std::cout << ")";
}

int ExpressionParenthesee::eval(TableDesSymboles *tablesDesSymboles) {
    LOG(INFO) << "ExpressionParenthesee::eval";
    return expression->eval(tablesDesSymboles);
}

void ExpressionParenthesee::executer(TableDesSymboles *tableDesSymboles) { }


bool ExpressionParenthesee::estConstante(TableDesSymboles *tableDesSymboles) {
    return this->expression->estConstante(tableDesSymboles);
}

void ExpressionParenthesee::optimiser(TableDesSymboles *tableDesSymboles) {
    this->expression->optimiser(tableDesSymboles);
    if (this->expression->estConstante(tableDesSymboles)) {
        int val = this->expression->eval(tableDesSymboles);
        Expression *expr = new ConstanteNumerique(
                new NumTerminal(val, this->expression->getLigne(), this->expression->getColonne()));
        delete this->expression;
        this->expression = expr;
    }
    else {
        // si on a pu remplacer par une constante numerique on tente une simplification
        Expression *exp;
        exp = this->expression->simplifier(tableDesSymboles);
        if (exp != nullptr) {
            delete this->expression;
            this->expression = exp;
        }
    }
}

bool ExpressionParenthesee::analyser(TableDesSymboles *tableDesSymboles) {
    return this->expression->analyser(tableDesSymboles);
}

Expression *ExpressionParenthesee::simplifier(TableDesSymboles *tableDesSymboles) {
    return nullptr;
}
