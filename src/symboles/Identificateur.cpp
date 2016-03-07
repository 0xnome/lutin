#include "Identificateur.h"

void Identificateur::setSuivant(Identificateur* suiv){
    this->suivant = suiv;
}

Identificateur * Identificateur::getSuivant()
{
    return this->suivant;
}

void Identificateur::afficher()
{
    std::cout << this->identifiant;
}
