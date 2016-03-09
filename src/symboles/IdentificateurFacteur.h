#ifndef LUTIN_IDENTIFICATEURFACTEUR_H
#define LUTIN_IDENTIFICATEURFACTEUR_H


#include "Facteur.h"
#include "IdTerminal.h"

class IdentificateurFacteur : public Facteur
{
public:
    IdentificateurFacteur(IdTerminal * idTerminal) : Facteur(IDENTIFICATEUR_FACTEUR)
    {
        this->id = idTerminal;
    }

    ~IdentificateurFacteur()
    {
        delete id;
    }

protected:
    IdTerminal * id;
};


#endif //LUTIN_IDENTIFICATEURFACTEUR_H
