#ifndef LUTIN_PROGRAMME_H
#define LUTIN_PROGRAMME_H

#include "BlocDeclaration.h"
#include "BlocInstruction.h"
#include "Symbole.h"

class Programme : public Symbole
{
public:
    Programme(BlocDeclaration *blocDeclaration, BlocInstruction *blocInstruction);

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual void afficher();

    virtual void analyser();

    virtual void optimiser();

    ~Programme();


protected:
    BlocDeclaration *blocDeclaration;
    BlocInstruction *blocInstruction;
};


#endif