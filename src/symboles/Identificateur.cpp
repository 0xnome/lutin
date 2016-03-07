#include "Identificateur.h"

void Identificateur::setSuivant(Identificateur* suiv){
    this->suivant = suiv;
}
void Identificateur::setDeclarationVariable(DeclarationVariable* variable){
    this->declarationVariable = variable;
}

