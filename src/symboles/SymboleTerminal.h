#ifndef LUTIN_SYMBOLE_TERMINAL_H
#define LUTIN_SYMBOLE_TERMINAL_H

#include "Symbole.h"

class SymboleTerminal : public Symbole
{
public:
    SymboleTerminal(int id) : Symbole(id), ligne(0), colonne(0)
    { };

    SymboleTerminal(int id, unsigned ligne, unsigned colonne) : Symbole(id), ligne(ligne), colonne(colonne)
    { };

    unsigned getLigne()
    { return ligne; }

    unsigned getColonne()
    { return colonne; }


protected:

    std::string nom;
    unsigned ligne;
    unsigned colonne;
};


#endif
