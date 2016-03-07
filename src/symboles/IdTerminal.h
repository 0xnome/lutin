#ifndef LUTIN_IDTERMINAL_H
#define LUTIN_IDTERMINAL_H

#include "Symbole.h"
#include <String>


class IdTerminal : public Symbole
{
public:
    String IdName;
    IdTerminal();
    ~IdTerminal();
};


#endif //LUTIN_IDTERMINAL_H
