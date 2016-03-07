#ifndef LUTIN_PROGRAMME_H
#define LUTIN_PROGRAMME_H

#include "BlocDeclaration.h"
#include "BlocInstruction.h"
#include "Symbole.h"

class Programme : public Symbole
{
public:
    Programme(int id, BlocDeclaration *blocDeclaration, BlocInstruction *blocInstruction);

    void executer();

    void afficher();

    void analyser();

    void optimiser();

    ~Programme();


protected:
    BlocDeclaration *blocDeclaration;
    BlocInstruction *blocInstruction;
};


#endif