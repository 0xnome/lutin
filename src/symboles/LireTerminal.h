#ifndef LUTIN_LIRETERMINAL_H
#define LUTIN_LIRETERMINAL_H

#include "Symbole.h"


class LireTerminal : public Symbole
{
public:
    LireTerminal():Symbole(LIRE_TERMINAL){}
    ~LireTerminal(){}
};


#endif //LUTIN_LIRETERMINAL_H
