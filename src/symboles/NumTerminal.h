#ifndef LUTIN_NUMTERMINAL_H
#define LUTIN_NUMTERMINAL_H

#include "SymboleTerminal.h"


class NumTerminal : public SymboleTerminal
{
public:
    NumTerminal(int val, unsigned ligne, unsigned colonne) : SymboleTerminal(NUM_TERMINAL, ligne, colonne), value(val)
    { };

    ~NumTerminal()
    { }

    void afficher()
    {
        std::cout << value;
    }

    int getValue()
    {
        return value;
    }

protected:
    int value;
};


#endif //LUTIN_NUMTERMINAL_H
