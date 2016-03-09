#ifndef LUTIN_BLOCDECLARATION_H
#define LUTIN_BLOCDECLARATION_H

#include "Symbole.h"

class BlocDeclaration : public Symbole
{
public:
    BlocDeclaration() : Symbole(BLOC_DECLARATION)
    {
        this->suivant = nullptr;
    };

    void setSuivant(BlocDeclaration *blocDeclaration)
    {
        this->suivant = blocDeclaration;
    }

    BlocDeclaration *getSuivant() const
    {
        return suivant;
    }

    virtual ~BlocDeclaration()
    { };

    virtual void executer() = 0;

    virtual void afficher() = 0;

    virtual void analyser() = 0;

    virtual void optimiser() = 0;

protected:
    BlocDeclaration(int id) : Symbole(id)
    { }

    BlocDeclaration *suivant;
};


#endif