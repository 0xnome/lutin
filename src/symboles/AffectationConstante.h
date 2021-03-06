#ifndef LUTIN_AFFECTATIONCONSTANTE_H
#define LUTIN_AFFECTATIONCONSTANTE_H

#include <TableDesSymboles.h>
#include "Symbole.h"
#include "IdTerminal.h"
#include "NumTerminal.h"

class AffectationConstante : public Symbole {
public:
    AffectationConstante(IdTerminal *id, NumTerminal *num);

    ~AffectationConstante();

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual void afficher();

    virtual bool analyser(TableDesSymboles *tableDesSymboles);

    virtual void optimiser(TableDesSymboles *tableDesSymboles);

    void setSuivant(AffectationConstante *suivant);

    AffectationConstante *getSuivant() const;

protected:
    IdTerminal *id;
    NumTerminal *num;
    AffectationConstante *suivant;
};


#endif
