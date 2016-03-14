#ifndef LUTIN_ERREURLEXICALE_H
#define LUTIN_ERREURLEXICALE_H

#include "Symbole.h"


class ErreurLexicale : public Symbole {
public:
    ErreurLexicale() : Symbole(ERREUR_LEXICALE) { }

    ~ErreurLexicale() { }
};


#endif //LUTIN_ERREURLEXICALE_H
