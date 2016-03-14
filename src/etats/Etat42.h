#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat42 : public EtatDefaut {
public:
    Etat42() : EtatDefaut("E42") { }

    int transition(Automate *automate, Symbole *s);
};
