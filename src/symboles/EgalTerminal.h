#ifndef LUTIN_EGALTERMINAL_H
#define LUTIN_EGALTERMINAL_H

#include "SymboleTerminal.h"


class EgalTerminal : public SymboleTerminal {
public:
    EgalTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(EGAL_TERMINAL, ligne, colonne) { }

    ~EgalTerminal() { }
};


#endif //LUTIN_EGALTERMINAL_H
