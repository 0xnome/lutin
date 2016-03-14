#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat23 : public EtatDefaut {
public:
    Etat23() : EtatDefaut("E23") { }

    int transition(Automate *automate, Symbole *s);
};
