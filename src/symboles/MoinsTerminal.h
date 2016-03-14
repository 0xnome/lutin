#ifndef LUTIN_MOINSTERMINAL_H
#define LUTIN_MOINSTERMINAL_H

#include "Symbole.h"

class MoinsTerminal : public Symbole {
public:
    MoinsTerminal() : Symbole(MOINS_TERMINAL) { }

    ~MoinsTerminal() { }
};

#endif //LUTIN_MOINSTERMINAL_H
