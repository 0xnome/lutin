#ifndef LUTIN_AFFECTTERMINAL_H
#define LUTIN_AFFECTTERMINAL_H

#include "Symbole.h"

class AffectTerminal : public Symbole
{
public:
    AffectTerminal():Symbole(AFFECT_TERMINAL){}
    ~AffectTerminal(){}
};

#endif //LUTIN_AFFECTTERMINAL_H
