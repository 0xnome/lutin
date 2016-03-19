#include "IdentificateurFacteur.h"

IdentificateurFacteur::IdentificateurFacteur(IdTerminal *idTerminal) : Facteur(IDENTIFICATEUR_FACTEUR), id(idTerminal) {
}

IdentificateurFacteur::~IdentificateurFacteur() {
    delete this->id;
}

void IdentificateurFacteur::afficher() {
    this->id->afficher();
}

int IdentificateurFacteur::eval(TableDesSymboles *tablesDesSymboles) {
    return tablesDesSymboles->getValeur(id->getNom());
}

void IdentificateurFacteur::executer(TableDesSymboles *tableDesSymboles) {
}
