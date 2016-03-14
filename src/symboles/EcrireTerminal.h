#ifndef LUTIN_ECRIRETERMINAL_H
#define LUTIN_ECRIRETERMINAL_H

#include "Symbole.h"

class EcrireTerminal : public Symbole {
public:
    EcrireTerminal() : Symbole(ECRIRE_TERMINAL) { }

    ~EcrireTerminal() { }
};


#endif //LUTIN_ECRIRETERMINAL_H
