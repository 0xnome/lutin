#ifndef LUTIN_ECRIRETERMINAL_H
#define LUTIN_ECRIRETERMINAL_H

#include "Symbole.h"

class EcrireTerminal : public Symbole
{
public:
    EcrireTerminal(unsigned ligne, unsigned colonne) : Symbole(ECRIRE_TERMINAL, ligne, colonne)
    { }

    ~EcrireTerminal()
    { }

};


#endif //LUTIN_ECRIRETERMINAL_H
