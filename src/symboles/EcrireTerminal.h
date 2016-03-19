#ifndef LUTIN_ECRIRETERMINAL_H
#define LUTIN_ECRIRETERMINAL_H

#include "SymboleTerminal.h"

class EcrireTerminal : public SymboleTerminal {
public:
    EcrireTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(ECRIRE_TERMINAL, ligne, colonne) { }

    ~EcrireTerminal() { }
};


#endif //LUTIN_ECRIRETERMINAL_H
