#include "AffectationConstante.h"


AffectationConstante::AffectationConstante(IdTerminal *idTerminal, NumTerminal *numT) : Symbole(AFFECTATION_CONSTANTE,
                                                                                                idTerminal->getLigne(),
                                                                                                idTerminal->getColonne()),
                                                                                        id(idTerminal), num(numT),
                                                                                        suivant(nullptr) {
}

void AffectationConstante::setSuivant(AffectationConstante *suiv) {
    this->suivant = suiv;
}

AffectationConstante::~AffectationConstante() {
    if (this->suivant != nullptr) {
        delete this->suivant;
    }
    delete this->id;
    delete this->num;
}

AffectationConstante *AffectationConstante::getSuivant() const {
    return suivant;
}

void AffectationConstante::executer(TableDesSymboles *tableDesSymboles) {
    tableDesSymboles->ajouterConstante(this->id->getNom(), this->id->getLigne(), this->id->getColonne(),
                                       this->num->getValue());
}

void AffectationConstante::afficher() {
    this->id->afficher();
    std::cout << "=";
    this->num->afficher();
}

bool AffectationConstante::analyser(TableDesSymboles *tableDesSymboles) {

    if (tableDesSymboles->estDeclaree(id->getNom())) {
        if (tableDesSymboles->estConstante(id->getNom())) {
            std::cout << "Erreur ligne " << id->getLigne() << ":" << this->id->getColonne() << " : "
            << id->getNom() << " est déjà déclarée à la ligne " << tableDesSymboles->getEntree(id->getNom())->ligne
            << std::endl;
            return false;
        } else {
            std::cout << "Erreur ligne " << id->getLigne() << ":" << this->id->getColonne() << " : " << id->getNom() <<
            " est déjà déclarée en tant que variable à la ligne " << tableDesSymboles->getEntree(id->getNom())->ligne
            << std::endl;
            return false;
        }

    } else {
        tableDesSymboles->ajouterConstante(this->id->getNom(), this->id->getLigne(), this->id->getColonne(),
                                           this->num->getValue());
    }

    return true;
}

void AffectationConstante::optimiser(TableDesSymboles *tableDesSymboles) {
}










