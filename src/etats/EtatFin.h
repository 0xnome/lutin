#ifndef LUTIN_ETATFIN_H
#define LUTIN_ETATFIN_H

#include "EtatDefaut.h"

class EtatFin: public EtatDefaut
{
public:
    EtatFin() : EtatDefaut("EFin")
    { }
};

#endif //LUTIN_ETATFIN_H
