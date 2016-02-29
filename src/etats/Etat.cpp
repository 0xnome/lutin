#include <iostream>
#include "Etat.h"
#include "../automate/Automate.h"
#include "../symboles/Symbole.h"

Etat::Etat(std::string nom)
{
    this->nom = nom;
}

bool Etat0::transition(Automate &automate, Symbole *s)
{
    switch (*s){
        case PROGRAMME:
            //automate.decalage(new Etat0());
            break;
        case BLOCS_DECLARATION:
            //automate.decalage(new Etat0());
            break;
    }
    return false;
}

Etat::~Etat()
{

}
