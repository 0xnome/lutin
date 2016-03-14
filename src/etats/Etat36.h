#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat36 : public EtatDefaut {
public:
    Etat36() : EtatDefaut("E36") { }

    int transition(Automate *automate, Symbole *s);
};
