#ifndef LUTIN_FACTEUR_H
#define LUTIN_FACTEUR_H


#include "Terme.h"

class Facteur : public Terme {

public:
    Facteur() : Terme(FACTEUR) { }

    virtual ~Facteur() { }

    virtual void afficher() = 0;

    virtual int eval(TableDesSymboles *tablesDesSymboles) = 0;

    virtual bool estConstante(TableDesSymboles *tableDesSymboles) = 0;
protected:
    Facteur(int id, unsigned ligne, unsigned colonne) : Terme(id, ligne, colonne) { }
};


#endif //LUTIN_FACTEUR_H
