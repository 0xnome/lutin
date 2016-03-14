#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat21 : public EtatDefaut {
public:
    Etat21() : EtatDefaut("E21") { }

    int transition(Automate *automate, Symbole *s);
};
