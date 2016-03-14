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
<<<<<<< 31f0344406bd278e3368abb5886f717374159ecb
    cout << expression->eval();
=======
>>>>>>> implements eval   TODO:identificateurFacteur::eval() is missing
}



