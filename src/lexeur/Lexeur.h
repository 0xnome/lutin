//
// Created by med on 07/03/16.
//

#ifndef LUTIN_LEXEUR_H
#define LUTIN_LEXEUR_H

#include <string>

class Lexeur {
public:
    Lexeur(std::string flux);
    std::string getNext();

private:
    std::string flux;
};


#endif //LUTIN_LEXEUR_H
