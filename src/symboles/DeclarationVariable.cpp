#include "DeclarationVariable.h"

DeclarationVariable::DeclarationVariable(IdentificateurVariable *identificateurVariable) : BlocDeclaration(
        DECLARATION_VARIABLE), identificateurVariable(identificateurVariable)
{
}

DeclarationVariable::~DeclarationVariable()
{
    if (this->identificateurVariable != nullptr)
    {
        delete this->identificateurVariable;
    }
}

void DeclarationVariable::afficher()
{
    IdentificateurVariable *id_courant = this->identificateurVariable;
    while (id_courant != nullptr)
    {
        std::cout << "var ";
        id_courant->afficher();
        std::cout << ';' << std::endl;
        id_courant = id_courant->getSuivant();
    }
}


void DeclarationVariable::optimiser()
{

}

void DeclarationVariable::executer(TableDesSymboles *tableDesSymboles)
{
    IdentificateurVariable *id_courant = this->identificateurVariable;
    while (id_courant != nullptr)
    {
        id_courant->executer(tableDesSymboles);
        id_courant = id_courant->getSuivant();
    }
}

bool DeclarationVariable::estVide()
{
    return identificateurVariable == nullptr;
}

void DeclarationVariable::optimiser(TableDesSymboles *symboles)
{
    // TODO
}

bool DeclarationVariable::analyser(TableDesSymboles *tableDesSymboles)
{
    bool ret = true;
    IdentificateurVariable *id_courant = this->identificateurVariable;
    while (id_courant != nullptr)
    {
        ret = ret && id_courant->analyser(tableDesSymboles);
        id_courant = id_courant->getSuivant();
    }
    return ret;
}
