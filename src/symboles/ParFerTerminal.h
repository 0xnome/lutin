#ifndef LUTIN_PARFERTERMINAL_H
#define LUTIN_PARFERTERMINAL_H

#include "SymboleTerminal.h"

class ParFerTerminal : public SymboleTerminal {
public:
    ParFerTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(PARFER_TERMINAL, ligne, colonne) { }

    ~ParFerTerminal() { }
};

#endif //LUTIN_PARFERTERMINAL_H
