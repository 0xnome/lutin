#ifndef LUTIN_LIRETERMINAL_H
#define LUTIN_LIRETERMINAL_H

#include "Symbole.h"


class LireTerminal : public Symbole
{
public:
    LireTerminal(unsigned ligne, unsigned colonne) : Symbole(LIRE_TERMINAL, ligne, colonne)
    { }

    ~LireTerminal()
    { }

    virtual void analyser(TableDesSymboles *tableDesSymboles)
    { };
};


#endif //LUTIN_LIRETERMINAL_H
