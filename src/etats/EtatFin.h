#ifndef LUTIN_ETATFIN_H
#define LUTIN_ETATFIN_H

#include "EtatDefaut.h"

class EtatFin: public EtatDefaut
{
public:
    EtatFin() : EtatDefaut("EFin")
    { }

    bool transition(Automate* automate, Symbole* s);

};

#endif //LUTIN_ETATFIN_H