#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat19 : public EtatDefaut {
public:
    Etat19() : EtatDefaut("E19") { }

    int transition(Automate *automate, Symbole *s);
};
