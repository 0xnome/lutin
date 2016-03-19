#ifndef LUTIN_VIRGULETERMINAL_H
#define LUTIN_VIRGULETERMINAL_H

#include "SymboleTerminal.h"


class VirguleTerminal : public SymboleTerminal {
public:
    VirguleTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(VIRGULE_TERMINAL, ligne, colonne) { };

    ~VirguleTerminal() { };
};


#endif //LUTIN_VIRGULETERMINAL_H
