#include <easyloggingpp.h>
#include "IdentificateurFacteur.h"

IdentificateurFacteur::IdentificateurFacteur(IdTerminal *idTerminal) : Facteur(IDENTIFICATEUR_FACTEUR), id(idTerminal)
{
}

IdentificateurFacteur::~IdentificateurFacteur()
{
    delete this->id;
}

void IdentificateurFacteur::afficher()
{
    this->id->afficher();
}

int IdentificateurFacteur::eval(TableDesSymboles *tablesDesSymboles)
{
    LOG(INFO) << "IdentificateurFacteur::eval";
    return *tablesDesSymboles->getValeur(id->getNom());
}

void IdentificateurFacteur::executer(TableDesSymboles *tableDesSymboles)
{
}

IdTerminal *IdentificateurFacteur::getId() const
{
    return id;
}

bool IdentificateurFacteur::estConstante(TableDesSymboles *tableDesSymboles)
{
    return tableDesSymboles->estConstante(id->getNom()) || (tableDesSymboles->estInitialisee(id->getNom()) && tableDesSymboles->getValeur(id->getNom()) != nullptr);
}

void IdentificateurFacteur::optimiser(TableDesSymboles *tableDesSymboles)
{
    return;
}

Expression *IdentificateurFacteur::simplifier(TableDesSymboles *tableDesSymboles) {
    return nullptr;
}

bool IdentificateurFacteur::analyser(TableDesSymboles *tableDesSymboles, Contexte contexte)
{
    contexte.validerDeclaration = true;
    contexte.validerInitialisation = true;

    // on dit que la variable a été utilisée
    tableDesSymboles->setVariableUtilisee(id->getNom());

    return this->id->analyser(tableDesSymboles, contexte);
}
