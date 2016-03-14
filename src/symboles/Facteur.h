#ifndef LUTIN_FACTEUR_H
#define LUTIN_FACTEUR_H


#include "Terme.h"

class Facteur : public Terme
{

public:
    Facteur() : Terme(FACTEUR)
    { }

    virtual ~Facteur()
    { }

    virtual void afficher() = 0;

    virtual int eval() = 0;

protected:
    Facteur(int id) : Terme(id)
    { }

};


#endif //LUTIN_FACTEUR_H
