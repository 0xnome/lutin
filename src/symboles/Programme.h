#ifndef LUTIN_PROGRAMME_H
#define LUTIN_PROGRAMME_H

#include "BlocDeclaration.h"
#include "BlocInstruction.h"
#include "Symbole.h"

class Programme : public Symbole {
public:
    Programme(BlocDeclaration *blocDeclaration, BlocInstruction *blocInstruction);

    ~Programme();

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual void afficher();

    Programme(int id);

    virtual bool analyser(TableDesSymboles *tableDesSymboles);

    virtual void optimiser(TableDesSymboles *tableDesSymboles);

protected:
    BlocDeclaration *blocDeclaration;

    BlocInstruction *blocInstruction;
};


#endif
