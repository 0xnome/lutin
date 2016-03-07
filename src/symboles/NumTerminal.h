#ifndef LUTIN_NUMTERMINAL_H
#define LUTIN_NUMTERMINAL_H

#include "Symbole.h"


class NumTerminal : public Symbole
{
public:
    int Value;
    NumTerminal(int val);
    ~NumTerminal();
};


#endif //LUTIN_NUMTERMINAL_H
