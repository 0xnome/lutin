#ifndef LUTIN_IDTERMINAL_H
#define LUTIN_IDTERMINAL_H

#include "SymboleTerminal.h"


class IdTerminal : public SymboleTerminal {
public:
    IdTerminal(std::string nom, unsigned ligne, unsigned colonne) : SymboleTerminal(ID_TERMINAL, ligne, colonne), nom(nom) { };

    ~IdTerminal() { }

    void afficher() {
        std::cout << nom;
    }

    std::string getNom() {
        return nom;
    }

protected:
    std::string nom;
};


#endif //LUTIN_IDTERMINAL_H
