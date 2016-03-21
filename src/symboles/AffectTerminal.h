#ifndef LUTIN_AFFECTTERMINAL_H
#define LUTIN_AFFECTTERMINAL_H

#include "Symbole.h"

class AffectTerminal : public Symbole
{
public:
    AffectTerminal(unsigned ligne, unsigned colonne) : Symbole(AFFECT_TERMINAL, ligne, colonne)
    { }

    ~AffectTerminal()
    { }

};

#endif //LUTIN_AFFECTTERMINAL_H
