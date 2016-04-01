#include "InstructionEcriture.h"
#include "ConstanteNumerique.h"

using namespace std;

InstructionEcriture::~InstructionEcriture() {
    if (this->expression != nullptr) {
        delete this->expression;
    }
}

InstructionEcriture::InstructionEcriture(Expression *expression) : BlocInstruction(INSTRUCTION_ECRITURE,
                                                                                   expression->getLigne(),
                                                                                   expression->getColonne()),
                                                                   expression(expression) {
}

void InstructionEcriture::afficher() {
    cout << "ecrire ";
    this->expression->afficher();
    cout << " ;" << endl;
}

void InstructionEcriture::executer(TableDesSymboles *tableDesSymboles) {
    cout << expression->eval(tableDesSymboles) << endl;
}


bool InstructionEcriture::estVide() {
    return this->expression == nullptr;
}


void InstructionEcriture::optimiser(TableDesSymboles *tableDesSymboles) {
    this->expression->optimiser(tableDesSymboles);
    if (this->expression->estConstante(tableDesSymboles)) {
        // CRemplacement par une constanteNumerique
        int val = this->expression->eval(tableDesSymboles);
        Expression *expr = new ConstanteNumerique(
                new NumTerminal(val, this->expression->getLigne(), this->expression->getColonne()));
        delete this->expression;
        this->expression = expr;
    } else {
        // si on a pu remplacer par une constante numerique on tente une simplification
        Expression *exp;
        exp = this->expression->simplifier(tableDesSymboles);
        if (exp != nullptr) {
            delete this->expression;
            this->expression = exp;
        }
    }
}

bool InstructionEcriture::analyser(TableDesSymboles *tableDesSymboles) {
    return expression->analyser(tableDesSymboles);
}
