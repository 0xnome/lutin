#ifndef LUTIN_MOINSTERMINAL_H
#define LUTIN_MOINSTERMINAL_H

#include "Symbole.h"

class MoinsTerminal : public Symbole
{
public:
    MoinsTerminal(unsigned ligne, unsigned colonne) : Symbole(MOINS_TERMINAL, ligne, colonne)
    { }

    ~MoinsTerminal()
    { }

    virtual void analyser(TableDesSymboles *tableDesSymboles)
    { };
};

#endif //LUTIN_MOINSTERMINAL_H
