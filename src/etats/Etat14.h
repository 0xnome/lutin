#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat14: public EtatDefaut
{
public:
    Etat14() : EtatDefaut("E14")
    { }
    bool transition(Automate* automate, Symbole* s);
};
