#ifndef LUTIN_BLOCDECLARATION_H
#define LUTIN_BLOCDECLARATION_H

#include <TableDesSymboles.h>
#include "Symbole.h"

class BlocDeclaration : public Symbole {
public:
    BlocDeclaration() : Symbole(BLOC_DECLARATION), suivant(nullptr) {
    }

    void setSuivant(BlocDeclaration *blocDeclaration) {
        this->suivant = blocDeclaration;
    }

    BlocDeclaration *getSuivant() const {
        return suivant;
    }

    virtual ~BlocDeclaration() {
        if (suivant != nullptr) {
            delete suivant;
        }
    }

    virtual void executer(TableDesSymboles *tableDesSymboles) = 0;

    virtual void afficher() = 0;

    virtual bool analyser(TableDesSymboles *tableDesSymboles, Contexte contexte) = 0;

    virtual void optimiser(TableDesSymboles *tableDesSymboles) = 0;

    virtual bool estVide() = 0;



protected:
    BlocDeclaration(int id) : Symbole(id), suivant(nullptr) {
    }

    BlocDeclaration *suivant;
};


#endif
