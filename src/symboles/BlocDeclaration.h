#ifndef LUTIN_BLOCDECLARATION_H
#define LUTIN_BLOCDECLARATION_H

#include "Symbole.h"

class BlocDeclaration : public Symbole
{
public:
    BlocDeclaration():Symbole(BLOC_DECLARATION){};

    ~BlocDeclaration(){};

    virtual void executer() = 0;

    virtual void afficher() = 0;

    virtual void analyser() = 0;

    virtual void optimiser() = 0;

protected:
    BlocDeclaration *suivant;
};


#endif