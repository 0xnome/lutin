#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat32 : public EtatDefaut {
public:
    Etat32() : EtatDefaut("E32") { }

    int transition(Automate *automate, Symbole *s);
};
