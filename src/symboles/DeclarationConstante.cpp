#include "DeclarationConstante.h"

DeclarationConstante::DeclarationConstante(AffectationConstante *affectationConstante): BlocDeclaration(DECLARATION_CONSTANTE)
{
    this->affectationConstante = affectationConstante;
}

DeclarationConstante::~DeclarationConstante()
{
    delete this->affectationConstante;
}

void DeclarationConstante::afficher() {
    AffectationConstante *affc_courant = this->affectationConstante;
    while (affc_courant != nullptr){
        std::cout << "const ";
        affc_courant->afficher();
        std::cout << ';' <<std::endl;
        affc_courant = affc_courant->getSuivant();
    }
}

void DeclarationConstante::analyser()
{
}

void DeclarationConstante::optimiser()
{
}

void DeclarationConstante::executer(TableDesSymboles *tableDesSymboles)
{

}

