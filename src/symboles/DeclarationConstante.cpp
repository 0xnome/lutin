#include "DeclarationConstante.h"

DeclarationConstante::DeclarationConstante(AffectationConstante *affectationConstante) : BlocDeclaration(
        DECLARATION_CONSTANTE), affectationConstante(affectationConstante)
{
}

DeclarationConstante::~DeclarationConstante()
{
    if (this->affectationConstante != nullptr)
    {
        delete this->affectationConstante;
    }
}

void DeclarationConstante::afficher()
{
    AffectationConstante *affc_courant = this->affectationConstante;
    while (affc_courant != nullptr)
    {
        std::cout << "const ";
        affc_courant->afficher();
        std::cout << ';' << std::endl;
        affc_courant = affc_courant->getSuivant();
    }
}


void DeclarationConstante::optimiser()
{
}

void DeclarationConstante::executer(TableDesSymboles *tableDesSymboles)
{
    AffectationConstante *affc_courant = this->affectationConstante;
    while (affc_courant != nullptr)
    {
        affc_courant->executer(tableDesSymboles);
        affc_courant = affc_courant->getSuivant();
    }
}

bool DeclarationConstante::estVide()
{
    return affectationConstante == nullptr;
}

void DeclarationConstante::optimiser(TableDesSymboles *symboles)
{
    // TODO
}

bool DeclarationConstante::analyser(TableDesSymboles *tableDesSymboles, Contexte contexte)
{
    bool ret = true;
    AffectationConstante *id_courant = this->affectationConstante;
    while (id_courant != nullptr)
    {
        ret = ret && id_courant->analyser(tableDesSymboles, contexte);
        id_courant = id_courant->getSuivant();
    }
    return ret;
}
