#include <iostream>
#include "Etat.h"

Etat::Etat(std::string nom)
{
    this->nom = nom;
}

bool Etat0::transition(Automate &automate, Symbole *s)
{
    switch (*s){
        case PROGRAMME:
            break;
        case DECLARATION_CONSTANTES:
            break;
    }
    return false;
}

Etat::~Etat()
{

}
