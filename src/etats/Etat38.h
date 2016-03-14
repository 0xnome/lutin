#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat38 : public EtatDefaut {
public:
    Etat38() : EtatDefaut("E38") { }

    int transition(Automate *automate, Symbole *s);
};
