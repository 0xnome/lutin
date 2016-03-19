#ifndef LUTIN_MOINSTERMINAL_H
#define LUTIN_MOINSTERMINAL_H

#include "SymboleTerminal.h"

class MoinsTerminal : public SymboleTerminal
{
public:
    MoinsTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(MOINS_TERMINAL, ligne, colonne)
    { }

    ~MoinsTerminal()
    { }
};

#endif //LUTIN_MOINSTERMINAL_H
