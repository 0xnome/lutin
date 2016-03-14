#ifndef LUTIN_PLUSTERMINAL_H
#define LUTIN_PLUSTERMINAL_H

#include "Symbole.h"

class PlusTerminal : public Symbole {
public:
    PlusTerminal() : Symbole(PLUS_TERMINAL) { }

    ~PlusTerminal() { }
};

#endif //LUTIN_PLUSTERMINAL_H
