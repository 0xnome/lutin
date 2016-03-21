#ifndef LUTIN_IDENTIFICATEUR_H
#define LUTIN_IDENTIFICATEUR_H

#include "Symbole.h"
#include "IdTerminal.h"

class IdentificateurVariable : public Symbole {
public:
    IdentificateurVariable(IdTerminal *idTerminal1);

    ~IdentificateurVariable();

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual void afficher();

    virtual bool analyser(TableDesSymboles *tableDesSymboles, Contexte contexte);

    virtual void optimiser(TableDesSymboles *tableDesSymboles);

    void setSuivant(IdentificateurVariable *suivant);

    IdentificateurVariable *getSuivant() const;

protected:
    IdTerminal *id;

    IdentificateurVariable *suivant;

};

#endif