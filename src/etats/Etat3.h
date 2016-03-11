#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat3: public EtatDefaut
{
public:
    Etat3() : EtatDefaut("E3")
    { }
    bool transition(Automate* automate, Symbole* s);
};
