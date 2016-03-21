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
};


#endif //LUTIN_LIRETERMINAL_H
