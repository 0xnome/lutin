#ifndef LUTIN_MULTTERMINAL_H
#define LUTIN_MULTTERMINAL_H

#include "Symbole.h"

class MultTerminal : public Symbole
{
public:
    MultTerminal(unsigned ligne, unsigned colonne) : Symbole(MULT_TERMINAL, ligne, colonne)
    { }

    ~MultTerminal()
    { }

    virtual bool analyser(TableDesSymboles *tableDesSymboles, Contexte contexte)
    { };
};

#endif //LUTIN_MULTTERMINAL_H
