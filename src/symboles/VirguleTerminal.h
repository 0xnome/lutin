#ifndef LUTIN_VIRGULETERMINAL_H
#define LUTIN_VIRGULETERMINAL_H

#include "Symbole.h"


class VirguleTerminal : public Symbole
{
public:
    VirguleTerminal():Symbole(VIRGULE_TERMINAL){};
    ~VirguleTerminal(){};
};


#endif //LUTIN_VIRGULETERMINAL_H
