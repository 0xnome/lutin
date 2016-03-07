#ifndef LUTIN_AFFECTATIONCONSTANTE_H
#define LUTIN_AFFECTATIONCONSTANTE_H

#include "Symbole.h"
#include "DeclarationConstante.h"

class AffectationConstante : public Symbole
{
public:
    AffectationConstante();
    ~AffectationConstante();
    void setSuivant(AffectationConstante* suivant);
    void setDeclarationConstante(DeclarationConstante* declarationConstante);
protected:
    AffectationConstante* suivant;
    DeclarationConstante* declarationConstante;
};


#endif