#ifndef LUTIN_NUMTERMINAL_H
#define LUTIN_NUMTERMINAL_H

#include "Symbole.h"


class NumTerminal : public Symbole
{
public:
    NumTerminal(int val, unsigned ligne, unsigned colonne) : Symbole(NUM_TERMINAL, ligne, colonne), value(val)
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
