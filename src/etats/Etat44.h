#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat44 : public EtatDefaut {
public:
    Etat44() : EtatDefaut("E44") { }

    int transition(Automate *automate, Symbole *s);
};
