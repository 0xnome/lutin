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
    cout << " ;" << endl;
}

void InstructionEcriture::executer(TableDesSymboles *tableDesSymboles)
{
    cout << expression->eval(tableDesSymboles) << endl;
}


bool InstructionEcriture::estVide()
{
    return this->expression == nullptr;
}


void InstructionEcriture::optimiser(TableDesSymboles *symboles)
{
    expression->optimiser(symboles);
}

bool InstructionEcriture::analyser(TableDesSymboles *tableDesSymboles, Contexte contexte)
{
    return expression->analyser(tableDesSymboles, contexte);
}
