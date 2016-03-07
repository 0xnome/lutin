//
// Created by med on 07/03/16.
//

#include "Lexeur.h"

Lexeur::Lexeur(std::vector<std::string> lignesDuFichier) {
    this->lignesDuFichier = lignesDuFichier;
}

std::string Lexeur::getNext() {
    return "none";
}