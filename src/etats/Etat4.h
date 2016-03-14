#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat4 : public EtatDefaut {
public:
    Etat4() : EtatDefaut("E4") { }

    int transition(Automate *automate, Symbole *s);
};
