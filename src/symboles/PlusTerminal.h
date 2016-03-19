#ifndef LUTIN_PLUSTERMINAL_H
#define LUTIN_PLUSTERMINAL_H

#include "SymboleTerminal.h"

class PlusTerminal : public SymboleTerminal {
public:
    PlusTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(PLUS_TERMINAL, ligne, colonne) { }

    ~PlusTerminal() { }
};

#endif //LUTIN_PLUSTERMINAL_H
