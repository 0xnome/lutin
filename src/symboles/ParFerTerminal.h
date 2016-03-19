#ifndef LUTIN_PARFERTERMINAL_H
#define LUTIN_PARFERTERMINAL_H

#include "Symbole.h"

class ParFerTerminal : public Symbole
{
public:
    ParFerTerminal(unsigned ligne, unsigned colonne) : Symbole(PARFER_TERMINAL, ligne, colonne)
    { }

    ~ParFerTerminal() { }
};

#endif //LUTIN_PARFERTERMINAL_H
