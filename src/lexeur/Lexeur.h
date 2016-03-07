//
// Created by med on 07/03/16.
//

#ifndef LUTIN_LEXEUR_H
#define LUTIN_LEXEUR_H

#include <string>
#include <vector>
#include <boost/regex/v4/regex_fwd.hpp>

class Lexeur {
public:
    Lexeur(std::vector<std::string> lignesDuFichier);
    std::string getNext();

private:
    std::vector<std::string> lignesDuFichier;
};

#endif //LUTIN_LEXEUR_H
