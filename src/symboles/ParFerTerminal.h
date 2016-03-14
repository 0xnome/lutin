#ifndef LUTIN_PARFERTERMINAL_H
#define LUTIN_PARFERTERMINAL_H

#include "Symbole.h"

class ParFerTerminal : public Symbole {
public:
    ParFerTerminal() : Symbole(PARFER_TERMINAL) { }

    ~ParFerTerminal() { }
};

#endif //LUTIN_PARFERTERMINAL_H
