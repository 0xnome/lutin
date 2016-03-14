#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat9 : public EtatDefaut {
public:
    Etat9() : EtatDefaut("E9") { }

    int transition(Automate *automate, Symbole *s);
};
