#include <iostream>
#include "EtatDefaut.h"
#include "Automate.h"
#include "Symbole.h"

class Etat10: public EtatDefaut
{
public:
    Etat10() : EtatDefaut("E10")
    { }
    bool transition(Automate* automate, Symbole* s);
};
