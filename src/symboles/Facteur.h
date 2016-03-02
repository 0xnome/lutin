#ifndef LUTIN_FACTEUR_H
#define LUTIN_FACTEUR_H


#include "Terme.h"

class Facteur : public Terme
{
protected:
    Facteur(int id) : Terme(id){ }
public:
    Facteur():Terme(FACTEUR){}
};


#endif //LUTIN_FACTEUR_H
