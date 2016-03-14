#ifndef LUTIN_PAROUVTERMINAL_H
#define LUTIN_PAROUVTERMINAL_H

#include "Symbole.h"

class ParOuvTerminal : public Symbole {
public:
    ParOuvTerminal() : Symbole(PAROUV_TERMINAL) { }

    ~ParOuvTerminal() { }
};

#endif //LUTIN_PAROUVTERMINAL_H
