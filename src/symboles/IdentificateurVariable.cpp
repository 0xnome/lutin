#include <TableDesSymboles.h>
#include "IdentificateurVariable.h"

IdentificateurVariable::IdentificateurVariable(IdTerminal *idTerminal) : Symbole(IDENTIFICATEUR_VARIABLE),
                                                                         id(idTerminal), suivant(nullptr) {
}

IdentificateurVariable::~IdentificateurVariable() {
    delete this->id;
    if (this->suivant != nullptr) {
        delete this->suivant;
    }
}

void IdentificateurVariable::setSuivant(IdentificateurVariable *suiv) {
    this->suivant = suiv;
}

void IdentificateurVariable::afficher() {
    std::cout << this->identifiant;
}

IdentificateurVariable *IdentificateurVariable::getSuivant() const {
    return suivant;
}

void IdentificateurVariable::executer(TableDesSymboles *tableDesSymboles) {
    tableDesSymboles->ajouterVariable(this->id->getNom());
}

void IdentificateurVariable::analyser() {
    //TODO
}

void IdentificateurVariable::optimiser() {
    //TODO
}








