#ifndef LUTIN_CONSTTERMINAL_H
#define LUTIN_CONSTTERMINAL_H

#include "Symbole.h"


class ConstTerminal : public Symbole {
public:
    ConstTerminal(unsigned ligne, unsigned colonne) : Symbole(CONST_TERMINAL, ligne, colonne) { }

    ~ConstTerminal() { }

};


#endif //LUTIN_CONSTTERMINAL_H
