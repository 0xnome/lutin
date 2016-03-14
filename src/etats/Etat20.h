#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat20 : public EtatDefaut {
public:
    Etat20() : EtatDefaut("E20") { }

    int transition(Automate *automate, Symbole *s);
};
