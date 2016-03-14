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

    void afficher()
    {
        this->id->afficher();
    }

    int eval(TableDesSymboles *tablesDesSymboles){
        // tablesDesSymboles
        return 0;
    }


    ~IdentificateurFacteur()
    {
        delete this->id;
    }

protected:
    IdTerminal * id;
};


#endif //LUTIN_IDENTIFICATEURFACTEUR_H
