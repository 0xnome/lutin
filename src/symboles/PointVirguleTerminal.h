#ifndef LUTIN_POINTVIRGULETERMINAL_H
#define LUTIN_POINTVIRGULETERMINAL_H

#include "Symbole.h"


class PointVirguleTerminal : public Symbole
{
public:
    PointVirguleTerminal(unsigned ligne, unsigned colonne) : Symbole(POINT_VIRGULE_TERMINAL, ligne, colonne)
    { }

    ~PointVirguleTerminal()
    { }
};


#endif //LUTIN_POINTVIRGULETERMINAL_H
