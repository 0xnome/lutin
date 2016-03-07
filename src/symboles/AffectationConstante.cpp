#include "AffectationConstante.h"

void AffectationConstante::setSuivant(AffectationConstante* suiv){
  this->suivant = suiv;

}
void AffectationConstante::setDeclarationConstante(DeclarationConstante* constante){
  this->declarationConstante = constante;
}


