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

}


