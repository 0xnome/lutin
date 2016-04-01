#ifndef LUTIN_FINPROGRAMME_H
#define LUTIN_FINPROGRAMME_H


#include "Symbole.h"

class FinProgramme : public Symbole {
public:
    FinProgramme(unsigned ligne, unsigned colonne) : Symbole(FIN_PROGRAMME, ligne, colonne) { }

    ~FinProgramme() { }
};


#endif //LUTIN_FINPROGRAMME_H
