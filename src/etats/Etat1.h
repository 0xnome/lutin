#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat1: public EtatDefaut
{
public:
    Etat1() : EtatDefaut("E1")
    { }
    bool transition(Automate* automate, Symbole* s);
};
