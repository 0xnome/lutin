#ifndef LUTIN_VARTERMINAL_H
#define LUTIN_VARTERMINAL_H

#include "Symbole.h"


class VarTerminal : public Symbole
{
public:
    VarTerminal() : Symbole(VAR_TERMINAL)
    {

    }

    ~VarTerminal()
    {
        
    }
};


#endif //LUTIN_VARTERMINAL_H
