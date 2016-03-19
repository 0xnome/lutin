#ifndef LUTIN_VARTERMINAL_H
#define LUTIN_VARTERMINAL_H

#include "SymboleTerminal.h"


class VarTerminal : public SymboleTerminal {
public:
    VarTerminal(unsigned ligne, unsigned colonne) : SymboleTerminal(VAR_TERMINAL, ligne, colonne) { }

    ~VarTerminal() { }
};


#endif //LUTIN_VARTERMINAL_H
