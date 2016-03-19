#ifndef LUTIN_AFFECTTERMINAL_H
#define LUTIN_AFFECTTERMINAL_H

#include "SymboleTerminal.h"

class AffectTerminal : public SymboleTerminal
{
public:
    AffectTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(AFFECT_TERMINAL, ligne, colonne)
    { }

    ~AffectTerminal()
    { }
};

#endif //LUTIN_AFFECTTERMINAL_H
