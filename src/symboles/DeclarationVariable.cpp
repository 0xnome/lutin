#include "DeclarationVariable.h"

void DeclarationVariable::afficher()
{
    IdentificateurVariable * id_courant = this->identificateurVariable;
    while (id_courant != nullptr){
        std::cout << "var ";
        id_courant->afficher();
        std::cout << ';' <<std::endl;
        id_courant = id_courant->getSuivant();
    }
}

DeclarationVariable::DeclarationVariable(IdentificateurVariable *identificateurVariable1):BlocDeclaration(DECLARATION_VARIABLE)
{
    this->identificateurVariable = identificateurVariable1;
}

DeclarationVariable::~DeclarationVariable()
{
    delete this->identificateurVariable;
}


void DeclarationVariable::analyser()
{

}

void DeclarationVariable::optimiser()
{

}

void DeclarationVariable::executer(TableDesSymboles *tableDesSymboles)
{

}




