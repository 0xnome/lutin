#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat15 : public EtatDefaut {
public:
    Etat15() : EtatDefaut("E15") { }

    int transition(Automate *automate, Symbole *s);
};
