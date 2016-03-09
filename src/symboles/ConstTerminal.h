#ifndef LUTIN_CONSTTERMINAL_H
#define LUTIN_CONSTTERMINAL_H

#include "Symbole.h"


class ConstTerminal : public Symbole
{
public:
    ConstTerminal():Symbole(CONST_TERMINAL){}
    ~ConstTerminal(){}
};


#endif //LUTIN_CONSTTERMINAL_H
