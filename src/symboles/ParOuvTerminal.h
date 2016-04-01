#ifndef LUTIN_PAROUVTERMINAL_H
#define LUTIN_PAROUVTERMINAL_H

#include "Symbole.h"

class ParOuvTerminal : public Symbole {
public:
    ParOuvTerminal(unsigned ligne, unsigned colonne) : Symbole(PAROUV_TERMINAL, ligne, colonne) { }

    ~ParOuvTerminal() { }
};

#endif //LUTIN_PAROUVTERMINAL_H
