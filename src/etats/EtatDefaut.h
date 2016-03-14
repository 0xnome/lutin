#ifndef LUTIN_ETATDEFAUT_H
#define LUTIN_ETATDEFAUT_H

#include <string>
#include <iostream>

#include "Automate.h"
#include "Symbole.h"
#include "EtatInterface.h"

class EtatDefaut : public EtatInterface {
public:

    EtatDefaut(std::string nom) : EtatInterface(nom) { }

    virtual ~EtatDefaut() { };

    virtual int transition(Automate *automate, Symbole *s);
};

#endif //LUTIN_ETATDEFAUT_H
