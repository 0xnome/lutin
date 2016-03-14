#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat13 : public EtatDefaut {
public:
    Etat13() : EtatDefaut("E13") { }

    int transition(Automate *automate, Symbole *s);
};
