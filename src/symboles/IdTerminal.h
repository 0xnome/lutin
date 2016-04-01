#ifndef LUTIN_IDTERMINAL_H
#define LUTIN_IDTERMINAL_H

#include "Symbole.h"


class IdTerminal : public Symbole {
public:
    IdTerminal(std::string nom, unsigned ligne, unsigned colonne) : Symbole(ID_TERMINAL, ligne, colonne), nom(nom) { };

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
