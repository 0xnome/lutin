#include <easyloggingpp.h>
#include "InstructionAffectation.h"
#include "ConstanteNumerique.h"

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
    LOG(INFO) << "InstructionAffectation::executer";
    tableDesSymboles->setVariableValeur(id->getNom(), expression->eval(tableDesSymboles));
}

bool InstructionAffectation::estVide()
{
    return this->expression == nullptr && this->id == nullptr;
}

bool InstructionAffectation::analyser(TableDesSymboles *tableDesSymboles)
{
    bool ret = true;
    if (tableDesSymboles->estDeclaree(id->getNom()))
    {
        if (tableDesSymboles->estConstante(id->getNom()))
        {
            std::cerr << "Erreur ligne " << this->id->getLigne() << ":" << this->id->getColonne() << " : " <<
            this->id->getNom() <<
            " est une constante et ne peut pas être modifiée." << std::endl;
            ret = false;
        } else
        {
            tableDesSymboles->estInitialisee(id->getNom());
        }
    } else
    {
        std::cerr << "Erreur ligne " << this->id->getLigne() << ":" << this->id->getColonne() << " : " <<
        this->id->getNom() <<
        " n'a pas été déclarée." << std::endl;
        ret = false;
    }
    ret = ret && expression->analyser(tableDesSymboles);

    return ret;
}

void InstructionAffectation::optimiser(TableDesSymboles *tableDesSymboles) {
    expression->optimiser(tableDesSymboles);
    this->expression->optimiser(tableDesSymboles);
    if(this->expression->estConstante(tableDesSymboles)){
        int val = this->expression->eval(tableDesSymboles);
        Expression *expr = new ConstanteNumerique(new NumTerminal(val, this->expression->getLigne(), this->expression->getColonne()));
        delete this->expression;
        this->expression = expr;
        tableDesSymboles->setVariableValeur(id->getNom(), val);
    }
    else{
        Expression *exp;
        while ((exp = this->expression->simplifier(tableDesSymboles))!= nullptr){
            delete this->expression;
            this->expression = exp;
        }
    }
}
