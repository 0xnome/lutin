#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat35: public EtatDefaut
{
public:
    Etat35() : EtatDefaut("E35")
    { }
    bool transition(Automate* automate, Symbole* s);
};
