#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat16 : public EtatDefaut {
public:
    Etat16() : EtatDefaut("E16") { }

    int transition(Automate *automate, Symbole *s);
};
