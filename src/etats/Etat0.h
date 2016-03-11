#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat0: public EtatDefaut
{
public:
    Etat0() : EtatDefaut("E0")
    { }
    bool transition(Automate* automate, Symbole* s);
};
