#ifndef LUTIN_PLUSTERMINAL_H
#define LUTIN_PLUSTERMINAL_H

#include "Symbole.h"

class PlusTerminal : public Symbole
{
public:
    PlusTerminal(unsigned ligne, unsigned colonne) : Symbole(PLUS_TERMINAL, ligne, colonne)
    { }

    ~PlusTerminal()
    { }

    virtual bool analyser(TableDesSymboles *tableDesSymboles, Contexte contexte)
    { };

};

#endif //LUTIN_PLUSTERMINAL_H
