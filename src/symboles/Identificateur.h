#ifndef LUTIN_IDENTIFICATEUR_H
#define LUTIN_IDENTIFICATEUR_H

#include "Symbole.h"
#include "DeclarationVariable.h"

class Identificateur : public Symbole
{
public:
    Identificateur();
    ~Identificateur();
    void setSuivant(Identificateur* suiv);
    void setDeclarationVariable(DeclarationVariable* variable);
protected:
    Identificateur* suivant;
    DeclarationVariable* declarationVariable;
};

#endif