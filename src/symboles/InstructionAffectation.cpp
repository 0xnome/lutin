#include "InstructionAffectation.h"

using namespace std;



void InstructionAffectation::afficher()
{
    this->id->afficher();
    cout<<" := ";
    this->expression->afficher();
    cout<<" ;";
}

void InstructionAffectation::executer(TableDesSymboles *tableDesSymboles)
{

}


InstructionAffectation::~InstructionAffectation() {
    delete this->expression;
    delete this->id;
}

bool InstructionAffectation::estVide() {
    return this->expression == nullptr && this->id == nullptr;
}

void InstructionAffectation::analyser() {

}

void InstructionAffectation::optimiser() {

}
