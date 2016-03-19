#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat43 : public EtatDefaut {
public:
    Etat43() : EtatDefaut("E43") { }

    int transition(Automate *automate, Symbole *s);
};
