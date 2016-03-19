#ifndef LUTIN_POINTVIRGULETERMINAL_H
#define LUTIN_POINTVIRGULETERMINAL_H

#include "SymboleTerminal.h"


class PointVirguleTerminal : public SymboleTerminal
{
public:
    PointVirguleTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(POINT_VIRGULE_TERMINAL, ligne, colonne)
    { }

    ~PointVirguleTerminal()
    { }
};


#endif //LUTIN_POINTVIRGULETERMINAL_H
