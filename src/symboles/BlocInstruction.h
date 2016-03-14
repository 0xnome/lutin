#ifndef LUTIN_BLOCINSTRUCTION_H
#define LUTIN_BLOCINSTRUCTION_H

#include "Symbole.h"

class BlocInstruction : public Symbole {

public:
    BlocInstruction() : Symbole(BLOC_INSTRUCTION), suivant(nullptr) {
    }

    virtual ~BlocInstruction() {
        if (suivant != nullptr) {
            delete suivant;
        }
    }

    BlocInstruction *getSuivant() const {
        return suivant;
    }


    void setSuivant(BlocInstruction *suivant) {
        BlocInstruction::suivant = suivant;
    }

    virtual void executer(TableDesSymboles *tableDesSymboles) = 0;

    virtual void afficher() = 0;

    virtual void analyser() = 0;

    virtual void optimiser() = 0;

    virtual bool estVide() = 0;

protected:
    BlocInstruction(int id) : Symbole(id), suivant(nullptr) {
    }

    BlocInstruction *suivant;
};


#endif