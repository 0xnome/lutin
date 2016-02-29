#include <iostream>
#include "Etat.h"

void Etat::print() const
{
    std::cout << this->nom << std::endl;

}

Etat::Etat(std::string nom)
{
    this->nom = nom;
}

