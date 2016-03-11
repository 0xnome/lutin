#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat6: public EtatDefaut
{
public:
    Etat6() : EtatDefaut("E6")
    { }
    bool transition(Automate* automate, Symbole* s);
};
