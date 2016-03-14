#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat11 : public EtatDefaut {
public:
    Etat11() : EtatDefaut("E11") { }

    int transition(Automate *automate, Symbole *s);
};
