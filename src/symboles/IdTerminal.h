#ifndef LUTIN_IDTERMINAL_H
#define LUTIN_IDTERMINAL_H

#include "Symbole.h"


class IdTerminal : public Symbole
{
public:
    String IdName;
    IdTerminal(std::string name) : IdName(name)
    { }
    ~IdTerminal()
    { }
};


#endif //LUTIN_IDTERMINAL_H
