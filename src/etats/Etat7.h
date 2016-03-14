#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat7 : public EtatDefaut {
public:
    Etat7() : EtatDefaut("E7") { }

    int transition(Automate *automate, Symbole *s);
};
