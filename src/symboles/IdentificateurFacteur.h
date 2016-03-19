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

    int eval(TableDesSymboles *tablesDesSymboles);

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual void analyser(TableDesSymboles *tableDesSymboles);

protected:
    IdTerminal *id;
};


#endif //LUTIN_IDENTIFICATEURFACTEUR_H
