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
    //tableDesSymboles->setVariableValeur(id,expression->eval());
}





