#include "AffectationConstante.h"


AffectationConstante::AffectationConstante(IdTerminal *idTerminal, NumTerminal *numT) : Symbole(AFFECTATION_CONSTANTE),
                                                                                        id(idTerminal), num(numT),
                                                                                        suivant(nullptr)
{
}

void AffectationConstante::setSuivant(AffectationConstante *suiv)
{
    this->suivant = suiv;
}

AffectationConstante::~AffectationConstante()
{
    if (this->suivant != nullptr)
    {
        delete this->suivant;
    }
    delete this->id;
    delete this->num;
}

AffectationConstante *AffectationConstante::getSuivant() const
{
    return suivant;
}

void AffectationConstante::executer(TableDesSymboles *tableDesSymboles)
{
    tableDesSymboles->ajouterConstante(this->id->getNom(), this->id->getLigne(), this->id->getColonne(),
                                       this->num->getValue());
}

void AffectationConstante::afficher()
{
    this->id->afficher();
    std::cout << "=";
    this->num->afficher();
}

void AffectationConstante::analyser(TableDesSymboles *tableDesSymboles)
{

    if (tableDesSymboles->estDeclaree(id->getNom()))
    {
        if (tableDesSymboles->estConstante(id->getNom()))
        {
            std::cout << "Erreur ligne " << id->getLigne() << ":" << this->id->getColonne() << " : "
            << id->getNom() << " est déjà déclarée à la ligne " << tableDesSymboles->getEntree(id->getNom())->ligne
            << std::endl;
        } else
        {
            std::cout << "Erreur ligne " << id->getLigne() << ":" << this->id->getColonne() << " : " << id->getNom() <<
            " est déjà déclarée en tant que variable à la ligne " << tableDesSymboles->getEntree(id->getNom())->ligne
            << std::endl;
        }

    } else
    {
        tableDesSymboles->ajouterConstante(this->id->getNom(), this->id->getLigne(), this->id->getColonne(),
                                           this->num->getValue());
    }


}

void AffectationConstante::optimiser(TableDesSymboles *tableDesSymboles)
{
}










