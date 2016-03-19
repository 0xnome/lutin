#include "InstructionAffectation.h"

using namespace std;


InstructionAffectation::InstructionAffectation(Expression *expression, IdTerminal *idTerminal) : BlocInstruction(
        INSTRUCTION_AFFECTATION), expression(expression), id(idTerminal)
{
}

InstructionAffectation::~InstructionAffectation()
{
    if (this->expression != nullptr)
    {
        delete this->expression;
    }
    if (this->id != nullptr)
    {
        delete this->id;
    }
}


void InstructionAffectation::afficher()
{
    this->id->afficher();
    cout << " := ";
    this->expression->afficher();
    cout << " ;" << endl;
}

void InstructionAffectation::executer(TableDesSymboles *tableDesSymboles)
{
    tableDesSymboles->setVariableValeur(id->getNom(), expression->eval(nullptr));
}

bool InstructionAffectation::estVide()
{
    return this->expression == nullptr && this->id == nullptr;
}

void InstructionAffectation::analyser(TableDesSymboles *tableDesSymboles)
{
    if (tableDesSymboles->estDeclaree(id->getNom()))
    {
        if (tableDesSymboles->estConstante(id->getNom()))
        {
            std::cout << "Erreur ligne " << this->id->getLigne() << " : " << this->id->getNom() <<
            " est une constante et ne peut pas être modifiée." << std::endl;
        } else
        {
            tableDesSymboles->estInitialisee(id->getNom());
        }
    } else
    {
        std::cout << "Erreur ligne " << this->id->getLigne() << " : " << this->id->getNom() <<
        " n'a pas été déclarée." << std::endl;
    }

    expression->analyser(tableDesSymboles);

}

void InstructionAffectation::optimiser()
{

}
