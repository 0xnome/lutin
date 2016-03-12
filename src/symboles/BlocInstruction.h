#ifndef LUTIN_BLOCINSTRUCTION_H
#define LUTIN_BLOCINSTRUCTION_H

#include "Symbole.h"

class BlocInstruction : public Symbole
{

protected:
    BlocInstruction(int id) : Symbole(id)
    {
        this->suivant = nullptr;
    }

public:
    BlocInstruction() : Symbole(BLOC_INSTRUCTION)
    {
        this->suivant = nullptr;
    };

    virtual ~BlocInstruction()
    { };


    BlocInstruction *getSuivant() const
    {
        return suivant;
    }

    void setSuivant(BlocInstruction *suivant)
    {
        BlocInstruction::suivant = suivant;
    }

    virtual void executer() = 0;

    virtual void afficher() = 0;

    virtual void analyser() = 0;

    virtual void optimiser() = 0;

protected:
    BlocInstruction *suivant;
};


#endif