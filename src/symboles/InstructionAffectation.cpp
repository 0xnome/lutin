#include "InstructionAffectation.h"

using namespace std;


void InstructionAffectation::executer()
{
  //TODO
}

void InstructionAffectation::afficher()
{
  this->id->afficher();
  cout<<":=";
  this->expression->afficher();
}



