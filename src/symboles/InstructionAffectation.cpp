#include "InstructionAffectation.h"

using namespace std;


InstructionAffectation::InstructionAffectation(Expression *expression, IdTerminal *idTerminal) : BlocInstruction(
        INSTRUCTION_AFFECTATION), expression(expression), id(idTerminal) {
}

InstructionAffectation::~InstructionAffectation() {
    if(this->expression != nullptr){
        delete this->expression;
    }
    if(this->id != nullptr){
        delete this->id;
    }
}


void InstructionAffectation::afficher() {
    this->id->afficher();
    cout << " := ";
    this->expression->afficher();
    cout << " ;";
}

void InstructionAffectation::executer(TableDesSymboles *tableDesSymboles) {
    tableDesSymboles->setVariableValeur(id->getNom(), expression->eval(nullptr));
}

bool InstructionAffectation::estVide() {
    return this->expression == nullptr && this->id == nullptr;
}

void InstructionAffectation::analyser(TableDesSymboles* tableDesSymboles) {

}

void InstructionAffectation::optimiser() {

}
