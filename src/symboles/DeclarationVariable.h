#ifndef LUTIN_DECLARATIONVARIABLE_H
#define LUTIN_DECLARATIONVARIABLE_H

#include "DeclarationConstante.h"
#include "Identificateur.h"

class DeclarationVariable : public DeclarationConstante
{
public:
    DeclarationVariable();

    ~DeclarationVariable();

    virtual void executer();

    virtual void afficher();

    virtual void analyser();

    virtual void optimiser();

protected:
    Identificateur id;
};


#endif