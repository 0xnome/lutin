#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat8: public EtatDefaut
{
public:
    Etat8() : EtatDefaut("E8")
    { }
    bool transition(Automate* automate, Symbole* s);
};
