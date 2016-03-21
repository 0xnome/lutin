#ifndef LUTIN_VIRGULETERMINAL_H
#define LUTIN_VIRGULETERMINAL_H

#include "Symbole.h"


class VirguleTerminal : public Symbole
{
public:
    VirguleTerminal(unsigned ligne, unsigned colonne) : Symbole(VIRGULE_TERMINAL, ligne, colonne)
    { };

    ~VirguleTerminal()
    { };
};


#endif //LUTIN_VIRGULETERMINAL_H
