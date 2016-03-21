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

    virtual bool analyser(TableDesSymboles *tableDesSymboles);

    virtual void optimiser();

    virtual bool estVide();

    virtual void optimiser(TableDesSymboles*);

protected:
    AffectationConstante *affectationConstante;

};


#endif