#ifndef LUTIN_CONSTTERMINAL_H
#define LUTIN_CONSTTERMINAL_H

#include "SymboleTerminal.h"


class ConstTerminal : public SymboleTerminal {
public:
    ConstTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(CONST_TERMINAL, ligne, colonne) { }

    ~ConstTerminal() { }
};


#endif //LUTIN_CONSTTERMINAL_H
