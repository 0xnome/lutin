#ifndef LUTIN_CONSTANTENUMERIQUE_H
#define LUTIN_CONSTANTENUMERIQUE_H


#include <easyloggingpp.h>
#include "Facteur.h"
#include "NumTerminal.h"

class ConstanteNumerique : public Facteur
{

public:
    ConstanteNumerique(NumTerminal *numTerminal) : Facteur(CONSTANTE_NUMERIQUE), valeur(numTerminal)
    {
    }

    ~ConstanteNumerique()
    {
        delete this->valeur;
    }

    int eval(TableDesSymboles *tablesDesSymboles)
    {
        LOG(INFO) << "ConstanteNumerique::eval";
        return valeur->getValue();
    }

    void afficher()
    {
        this->valeur->afficher();
    }

    void executer(TableDesSymboles *tableDesSymboles)
    { }

    virtual bool analyser(TableDesSymboles *tableDesSymboles, Contexte contexte)
    {
        return true;
    };

    bool estConstante(TableDesSymboles *tableDesSymboles)
    {
        return true;
    }

    void optimiser(TableDesSymboles *tableDesSymboles)
    {
        return;
    }

    virtual Expression* simplifier(TableDesSymboles* tableDesSymboles){
        return nullptr;
    }

protected:
    NumTerminal *valeur;
};


#endif //LUTIN_CONTANTENUMERIQUE_H
