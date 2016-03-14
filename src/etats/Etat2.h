#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat2 : public EtatDefaut {
public:
    Etat2() : EtatDefaut("E2") { }

    int transition(Automate *automate, Symbole *s);
};
