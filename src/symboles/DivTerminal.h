#ifndef LUTIN_DIVTERMINAL_H
#define LUTIN_DIVTERMINAL_H

#include "Symbole.h"

class DivTerminal : public SymboleTerminal {
public:
    DivTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(DIV_TERMINAL, ligne, colonne) { }

    ~DivTerminal() { }
};

#endif //LUTIN_DIVTERMINAL_H
