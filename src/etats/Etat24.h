#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat24: public EtatDefaut
{
public:
    Etat24() : EtatDefaut("E24")
    { }
    bool transition(Automate* automate, Symbole* s);
};
