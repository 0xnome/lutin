#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat39 : public EtatDefaut {
public:
    Etat39() : EtatDefaut("E39") { }

    int transition(Automate *automate, Symbole *s);
};
