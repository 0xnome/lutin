#ifndef LUTIN_ERREURLEXICALE_H
#define LUTIN_ERREURLEXICALE_H

#include "Symbole.h"


class ErreurLexicale : public Symbole
{
public:
    ErreurLexicale(std::string message) : Symbole(ERREUR_LEXICALE)
    {
        this->message = message;
    }

    ~ErreurLexicale()
    { }

    std::string *getMessage()
    {
        return &message;
    }

private:
    std::string message;
};


#endif //LUTIN_ERREURLEXICALE_H
