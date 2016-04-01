#ifndef LUTIN_DIVTERMINAL_H
#define LUTIN_DIVTERMINAL_H

#include "Symbole.h"

class DivTerminal : public Symbole {
public:
    DivTerminal(unsigned ligne, unsigned colonne) : Symbole(DIV_TERMINAL, ligne, colonne) { }

    ~DivTerminal() { }
};

#endif //LUTIN_DIVTERMINAL_H
