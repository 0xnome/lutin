#ifndef LUTIN_PAROUVTERMINAL_H
#define LUTIN_PAROUVTERMINAL_H

#include "SymboleTerminal.h"

class ParOuvTerminal : public SymboleTerminal {
public:
    ParOuvTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(PAROUV_TERMINAL, ligne, colonne) { }

    ~ParOuvTerminal() { }
};

#endif //LUTIN_PAROUVTERMINAL_H
