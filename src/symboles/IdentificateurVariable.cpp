#include <TableDesSymboles.h>
#include "IdentificateurVariable.h"

IdentificateurVariable::IdentificateurVariable(IdTerminal *idTerminal) : Symbole(IDENTIFICATEUR_VARIABLE),
                                                                         id(idTerminal), suivant(nullptr)
{
}

IdentificateurVariable::~IdentificateurVariable()
{
    delete this->id;
    if (this->suivant != nullptr)
    {
        delete this->suivant;
    }
}

void IdentificateurVariable::setSuivant(IdentificateurVariable *suiv)
{
    this->suivant = suiv;
}

void IdentificateurVariable::afficher()
{
    this->id->afficher();
}

IdentificateurVariable *IdentificateurVariable::getSuivant() const
{
    return suivant;
}

void IdentificateurVariable::executer(TableDesSymboles *tableDesSymboles)
{
    tableDesSymboles->ajouterVariable(this->id->getNom(), this->id->getLigne(), this->id->getColonne());
}

void IdentificateurVariable::analyser(TableDesSymboles *tableDesSymboles)
{

    if (tableDesSymboles->estDeclaree(this->id->getNom()))
    {
        if (tableDesSymboles->estConstante(id->getNom()))
        {
            std::cout << "Erreur ligne " << this->id->getLigne() << " : " << this->id->getNom() <<
            " est déjà déclarée en tant que constante à la ligne " << tableDesSymboles->getEntree(id->getNom())->ligne
            << std::endl;
        } else
        {
            std::cout << "Erreur ligne " << this->id->getLigne() << " : " << this->id->getNom() <<
            " est déjà déclarée à la ligne " << tableDesSymboles->getEntree(id->getNom())->ligne
            << std::endl;
        }
    } else
    {
        tableDesSymboles->ajouterVariable(this->id->getNom(), this->id->getLigne(), this->id->getColonne());
    }
}

void IdentificateurVariable::optimiser()
{
    //TODO
}








