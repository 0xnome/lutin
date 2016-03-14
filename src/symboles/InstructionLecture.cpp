#include "InstructionLecture.h"

using namespace std;


void InstructionLecture::afficher()
{
    cout<<"lire ";
    this->id->afficher();
    cout<<" ;";
}

void InstructionLecture::executer(TableDesSymboles *tableDesSymboles)
{
    int val;
    cin >> val ;
    tableDesSymboles->setVariableValeur(id->getNom(),val);
}

bool InstructionLecture::estVide() {
    return this->id == nullptr;
}
