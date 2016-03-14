#ifndef LUTIN_MULTTERMINAL_H
#define LUTIN_MULTTERMINAL_H

#include "Symbole.h"

class MultTerminal : public Symbole {
public:
    MultTerminal() : Symbole(MULT_TERMINAL) { }

    ~MultTerminal() { }
};

#endif //LUTIN_MULTTERMINAL_H
