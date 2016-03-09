#ifndef LUTIN_IDENTIFICATEUR_H
#define LUTIN_IDENTIFICATEUR_H

#include "Symbole.h"
#include "IdTerminal.h"

class IdentificateurVariable : public Symbole
{
public:
    IdentificateurVariable(IdTerminal *idTerminal1);

    ~IdentificateurVariable();

    virtual void executer();

    virtual void afficher();

    virtual void analyser();

    virtual void optimiser();

    void setSuivant(IdentificateurVariable *suivant);

    IdentificateurVariable *getSuivant() const;

protected:
    IdentificateurVariable *suivant;
    IdTerminal *idTerminal;
public:

};

#endif