#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat37 : public EtatDefaut {
public:
    Etat37() : EtatDefaut("E37") { }

    int transition(Automate *automate, Symbole *s);
};
