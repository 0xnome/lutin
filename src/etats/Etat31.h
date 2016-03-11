#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat31: public EtatDefaut
{
public:
    Etat31() : EtatDefaut("E31")
    { }
    bool transition(Automate* automate, Symbole* s);
};
