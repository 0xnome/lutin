#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat33 : public EtatDefaut {
public:
    Etat33() : EtatDefaut("E33") { }

    int transition(Automate *automate, Symbole *s);
};
