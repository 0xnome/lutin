#ifndef LUTIN_CONSTANTENUMERIQUE_H
#define LUTIN_CONSTANTENUMERIQUE_H


#include "Facteur.h"
#include "NumTerminal.h"

class ConstanteNumerique : public Facteur
{

public:
    ConstanteNumerique(NumTerminal *numTerminal) : Facteur(CONSTANTE_NUMERIQUE)
    {
        this->valeur = numTerminal;
    }

    ~ConstanteNumerique()
    {
        delete this->valeur;
    }

    int eval()
    {
        return valeur->getValue();
    }


    void afficher()
    {
        this->valeur->afficher();
    }

protected:
    NumTerminal *valeur;
};


#endif //LUTIN_CONTANTENUMERIQUE_H
