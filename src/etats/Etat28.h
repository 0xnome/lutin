#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat28 : public EtatDefaut {
public:
    Etat28() : EtatDefaut("E28") { }

    int transition(Automate *automate, Symbole *s);
};
