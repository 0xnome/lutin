#ifndef LUTIN_DECLARATIONVARIABLE_H
#define LUTIN_DECLARATIONVARIABLE_H

#include "DeclarationConstante.h"
#include "IdentificateurVariable.h"

class DeclarationVariable : public BlocDeclaration
{
public:
    DeclarationVariable(IdentificateurVariable * identificateurVariable1);

    ~DeclarationVariable();

    virtual void executer();

    virtual void afficher();

    virtual void analyser();

    virtual void optimiser();

protected:
    IdentificateurVariable* identificateurVariable;
};


#endif