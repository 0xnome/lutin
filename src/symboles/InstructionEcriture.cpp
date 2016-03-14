#include "InstructionEcriture.h"

using namespace std;


void InstructionEcriture::afficher()
{
    cout<<"ecrire ";
    this->expression->afficher();
    cout<<" ;";
}

void InstructionEcriture::executer(TableDesSymboles *tableDesSymboles)
{
    cout << expression->eval(nullptr);
}


bool InstructionEcriture::estVide() {
    return this->expression == nullptr;
}
