#ifndef LUTIN_NUMTERMINAL_H
#define LUTIN_NUMTERMINAL_H

#include "Symbole.h"


class NumTerminal : public Symbole
{
public:
    NumTerminal(int val):Symbole(NUM_TERMINAL),value(val){};
    ~NumTerminal(){}

    void afficher(){
        std::cout<<value;
    }

protected:
    int value;
};


#endif //LUTIN_NUMTERMINAL_H
