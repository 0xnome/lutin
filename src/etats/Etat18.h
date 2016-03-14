#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat18 : public EtatDefaut {
public:
    Etat18() : EtatDefaut("E18") { }

    int transition(Automate *automate, Symbole *s);
};
