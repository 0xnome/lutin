#ifndef LUTIN_IDENTIFICATEUR_H
#define LUTIN_IDENTIFICATEUR_H

#include "Symbole.h"

class Identificateur : public Symbole
{
public:
    Identificateur();
    ~Identificateur();
    void setSuivant(Identificateur* suiv);

    Identificateur * getSuivant();

    virtual void executer();

    virtual void afficher();

    virtual void analyser();

    virtual void optimiser();

protected:
    Identificateur* suivant;
};

#endif