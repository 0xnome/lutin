#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat17 : public EtatDefaut {
public:
    Etat17() : EtatDefaut("E17") { }

    int transition(Automate *automate, Symbole *s);
};
