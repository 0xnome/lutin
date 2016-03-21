#ifndef LUTIN_IDENTIFICATEURFACTEUR_H
#define LUTIN_IDENTIFICATEURFACTEUR_H


#include "Facteur.h"
#include "IdTerminal.h"

class IdentificateurFacteur : public Facteur
{
public:
    IdentificateurFacteur(IdTerminal *idTerminal);

    ~IdentificateurFacteur();

    void afficher();

    virtual int eval(TableDesSymboles *tablesDesSymboles);

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual bool analyser(TableDesSymboles *tableDesSymboles, Contexte contexte);

    virtual bool estConstante(TableDesSymboles *tableDesSymboles);

    virtual void optimiser(TableDesSymboles* tableDesSymboles);

    virtual Expression* simplifier(TableDesSymboles* tableDesSymboles);


    IdTerminal *getId() const;
protected:
    IdTerminal *id;
};


#endif //LUTIN_IDENTIFICATEURFACTEUR_H
