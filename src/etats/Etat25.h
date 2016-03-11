#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat25: public EtatDefaut
{
public:
    Etat25() : EtatDefaut("E25")
    { }
    bool transition(Automate* automate, Symbole* s);
};
