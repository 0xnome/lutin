#include "InstructionEcriture.h"

using namespace std;

InstructionEcriture::~InstructionEcriture()
{
    if (this->expression != nullptr)
    {
        delete this->expression;
    }
}

InstructionEcriture::InstructionEcriture(Expression *expression) : BlocInstruction(INSTRUCTION_ECRITURE),
                                                                   expression(expression)
{
}

void InstructionEcriture::afficher()
{
    cout << "ecrire ";
    this->expression->afficher();
    cout << " ;";
}

void InstructionEcriture::executer(TableDesSymboles *tableDesSymboles)
{
    cout << expression->eval(nullptr);
}


bool InstructionEcriture::estVide()
{
    return this->expression == nullptr;
}


void InstructionEcriture::analyser(TableDesSymboles *tableDesSymboles)
{
    expression->analyser(tableDesSymboles);
}

void InstructionEcriture::optimiser()
{ }
