#ifndef LUTIN_BLOCINSTRUCTION_H
#define LUTIN_BLOCINSTRUCTION_H

#include "Symbole.h"

class BlocInstruction : public Symbole
{
public:
    BlocInstruction();

    ~BlocInstruction();

    virtual void executer();

    virtual void afficher();

    virtual void analyser();

    virtual void optimiser();

protected:
    BlocInstruction *suivant;
};


#endif