#include <easyloggingpp.h>
#include "ExpressionAdditive.h"
#include "ConstanteNumerique.h"

using namespace std;

ExpressionAdditive::ExpressionAdditive(Terme *terme, Expression *expression) : Expression(EXPRESSION_ADDITIVE,
                                                                                          expression->getLigne(),
                                                                                          expression->getColonne()),
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
    LOG(INFO) << "ExpressionAdditive::eval";
    if (terme->analyser(tablesDesSymboles) & expression->analyser(tablesDesSymboles)) {
        return (terme->eval(tablesDesSymboles) + expression->eval(tablesDesSymboles));
    } else {
        exit(1);
    }
}


void ExpressionAdditive::executer(TableDesSymboles *tableDesSymboles) {

}

bool ExpressionAdditive::estConstante(TableDesSymboles *tableDesSymboles) {
    return this->terme->estConstante(tableDesSymboles) && this->expression->estConstante(tableDesSymboles);
}

bool ExpressionAdditive::analyser(TableDesSymboles *tableDesSymboles) {
    return expression->analyser(tableDesSymboles) & terme->analyser(tableDesSymboles);
}

void ExpressionAdditive::optimiser(TableDesSymboles *tableDesSymboles) {
    this->expression->optimiser(tableDesSymboles);
    if (this->expression->estConstante(tableDesSymboles)) {
        int val = this->expression->eval(tableDesSymboles);
        Expression *expr = new ConstanteNumerique(
                new NumTerminal(val, this->expression->getLigne(), this->expression->getColonne()));
        delete this->expression;
        this->expression = expr;
    } else {
        // si on a pu remplacer par une constante numerique on tente une simplification
        Expression *expr;
        expr = (Expression *) this->expression->simplifier(tableDesSymboles);
        if (expr != nullptr) {
            delete this->expression;
            this->expression = expr;
        }
    }

    this->terme->optimiser(tableDesSymboles);
    if (this->terme->estConstante(tableDesSymboles)) {
        int val = this->terme->eval(tableDesSymboles);
        Terme *ter = new ConstanteNumerique(new NumTerminal(val, this->terme->getLigne(), this->terme->getColonne()));
        delete this->terme;
        this->terme = ter;
    } else {
        // si on a pu remplacer par une constante numerique on tente une simplification
        Terme *ter;
        ter = (Terme *) this->terme->simplifier(tableDesSymboles);
        if (ter != nullptr) {
            delete this->terme;
            this->terme = ter;
        }
    }

}

Expression *ExpressionAdditive::simplifier(TableDesSymboles *tableDesSymboles) {
    if (this->expression->estConstante(tableDesSymboles) &&
        this->expression->eval(tableDesSymboles) == ExpressionAdditive::ELEMENT_NEUTRE) {
        Expression *exp = (Expression *) this->terme;
        this->terme = nullptr;
        return exp;
    }
    else if (this->terme->estConstante(tableDesSymboles) &&
             this->terme->eval(tableDesSymboles) == ExpressionAdditive::ELEMENT_NEUTRE) {
        Expression *exp = this->expression;
        this->expression = nullptr;
        return exp;
    }
    return nullptr;
}
