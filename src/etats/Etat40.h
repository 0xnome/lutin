#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat40: public EtatDefaut
{
public:
    Etat40() : EtatDefaut("E40")
    { }
    bool transition(Automate* automate, Symbole* s);
};
