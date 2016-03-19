#ifndef LUTIN_MULTTERMINAL_H
#define LUTIN_MULTTERMINAL_H

#include "SymboleTerminal.h"

class MultTerminal : public SymboleTerminal {
public:
    MultTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(MULT_TERMINAL, ligne, colonne) { }

    ~MultTerminal() { }
};

#endif //LUTIN_MULTTERMINAL_H
