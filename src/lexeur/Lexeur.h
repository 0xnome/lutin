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
    Symbole* getNext();

private:
    std::vector<std::vector<std::string>> lignesDuProgramme;
    unsigned int ligne,colone;
    bool lectureTerminee;
};

#endif //LUTIN_LEXEUR_H
