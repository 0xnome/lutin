#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat26: public EtatDefaut
{
public:
    Etat26() : EtatDefaut("E26")
    { }
    bool transition(Automate* automate, Symbole* s);
};
