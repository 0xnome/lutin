#ifndef LUTIN_EGALTERMINAL_H
#define LUTIN_EGALTERMINAL_H

#include "Symbole.h"


class EgalTerminal : public Symbole
{
public:
    EgalTerminal(unsigned ligne, unsigned colonne) : Symbole(EGAL_TERMINAL, ligne, colonne)
    { }

    ~EgalTerminal() { }
};


#endif //LUTIN_EGALTERMINAL_H
