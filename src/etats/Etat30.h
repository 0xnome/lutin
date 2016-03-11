#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat30: public EtatDefaut
{
public:
    Etat30() : EtatDefaut("E30")
    { }
    bool transition(Automate* automate, Symbole* s);
};
