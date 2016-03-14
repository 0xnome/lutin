#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat34 : public EtatDefaut {
public:
    Etat34() : EtatDefaut("E34") { }

    int transition(Automate *automate, Symbole *s);
};
