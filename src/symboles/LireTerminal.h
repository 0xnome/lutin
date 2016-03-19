#ifndef LUTIN_LIRETERMINAL_H
#define LUTIN_LIRETERMINAL_H

#include "Symbole.h"


class LireTerminal : public SymboleTerminal {
public:
    LireTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(LIRE_TERMINAL, ligne, colonne) { }

    ~LireTerminal() { }
};


#endif //LUTIN_LIRETERMINAL_H
