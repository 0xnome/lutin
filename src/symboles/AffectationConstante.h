#ifndef LUTIN_AFFECTATIONCONSTANTE_H
#define LUTIN_AFFECTATIONCONSTANTE_H

#include "Symbole.h"
#include "IdTerminal.h"
#include "NumTerminal.h"

class AffectationConstante : public Symbole
{
public:
    AffectationConstante(IdTerminal *id, NumTerminal *num);

    ~AffectationConstante();


    virtual void executer();

    virtual void afficher();

    virtual void analyser();

    virtual void optimiser();

    void setSuivant(AffectationConstante *suivant);

    AffectationConstante *getSuivant() const;

protected:
    IdTerminal *id;
    NumTerminal *num;
    AffectationConstante *suivant;
};


#endif
