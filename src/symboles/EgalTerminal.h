#ifndef LUTIN_EGALTERMINAL_H
#define LUTIN_EGALTERMINAL_H

#include "Symbole.h"


class EgalTerminal : public Symbole
{
public:
    EgalTerminal() : Symbole(EGAL_TERMINAL)
    { }

    ~EgalTerminal(){}
};


#endif //LUTIN_EGALTERMINAL_H
