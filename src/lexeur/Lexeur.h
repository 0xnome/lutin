//
// Created by med on 07/03/16.
//

#ifndef LUTIN_LEXEUR_H
#define LUTIN_LEXEUR_H

#include <string>
#include <vector>
#include <boost/regex/v4/regex_fwd.hpp>
#include <Symbole.h>

class Lexeur {
public:
    Lexeur(std::vector<std::string> lignesDuFichier);

    ~Lexeur();

    // Déplace la tête de lecture et retourne le nouveau symbole courant
    Symbole *getNext();

    // Retourne le symbole courant
    Symbole *getCurrent();

    // Déplace la tête de lecture
    void shift();

private:
    std::vector<std::vector<std::string>> lignesDuProgramme;

    unsigned int ligne, colonne;

    bool lectureTerminee;

    Symbole *current;

    std::vector<std::string> lignesDuFichier;

    std::vector<unsigned long> index;

    std::size_t pos;
};

#endif //LUTIN_LEXEUR_H
