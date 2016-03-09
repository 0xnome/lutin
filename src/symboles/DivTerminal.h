#ifndef LUTIN_DIVTERMINAL_H
#define LUTIN_DIVTERMINAL_H

#include "Symbole.h"

class DivTerminal : public Symbole
{
public:
    DivTerminal():Symbole(DIV_TERMINAL){}
    ~DivTerminal(){}
};
#endif //LUTIN_DIVTERMINAL_H
