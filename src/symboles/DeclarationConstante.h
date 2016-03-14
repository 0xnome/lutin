#ifndef LUTIN_DECLARATIONCONSTANTE_H
#define LUTIN_DECLARATIONCONSTANTE_H

#include "BlocDeclaration.h"
#include "AffectationConstante.h"


class DeclarationConstante : public BlocDeclaration {
public:
    DeclarationConstante(AffectationConstante *affectationConstante);

    ~DeclarationConstante();

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual void afficher();

    virtual void analyser();

    virtual void optimiser();

    virtual bool estVide();

protected:
    AffectationConstante *affectationConstante;

};


#endif