#ifndef LUTIN_VARTERMINAL_H
#define LUTIN_VARTERMINAL_H

#include "Symbole.h"


class VarTerminal : public Symbole
{
public:
    VarTerminal(unsigned ligne, unsigned colonne) : Symbole(VAR_TERMINAL, ligne, colonne)
    { }

    ~VarTerminal()
    { }


    virtual void analyser(TableDesSymboles *tableDesSymboles)
    { };
};


#endif //LUTIN_VARTERMINAL_H

