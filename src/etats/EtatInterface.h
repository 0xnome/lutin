#ifndef LUTIN_ETATINTERFACE_H
#define LUTIN_ETATINTERFACE_H

#include <string>
#include <iostream>

#include "Automate.h"
#include "Symbole.h"

class Automate;
class EtatInterface
{
public:

    EtatInterface(std::string nom) : nom(nom) {}

    virtual ~EtatInterface(){};

    std::ostream &operator<<(std::ostream& os) {
        return os << this->nom;
    }

    virtual bool transition(Automate* automate, Symbole *s) = 0;

protected:
    std::string nom;
};

#endif //LUTIN_ETATINTERFACE_H
