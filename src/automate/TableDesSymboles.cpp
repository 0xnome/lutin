#include "TableDesSymboles.h"

using namespace std;

TableDesSymboles::TableDesSymboles()
{

}

TableDesSymboles::~TableDesSymboles()
{

}

bool TableDesSymboles::estUtilisee(string nomVariable) const
{
    //TODO
    return false;
}

bool TableDesSymboles::estInitialisee(string nomVariable) const
{
    //TODO
    return false;
}

bool TableDesSymboles::estDeclaree(string nomVariable) const
{
    return this->tableVariables.find(nomVariable) != this->tableVariables.end() ||
           this->tableConstantes.find(nomVariable) != this->tableConstantes.end();
}

void TableDesSymboles::ajouterConstante(string nomConstante, int valeurConstante)
{
    Entree constEntree = {true, false, valeurConstante};
    this->tableConstantes[nomConstante] = constEntree;
}

void TableDesSymboles::ajouterVariable(std::string nomVariable)
{
    Entree varEntree = {false, false};
    this->tableVariables[nomVariable] = varEntree;
}

void TableDesSymboles::setVariableUtilisee(std::string nomVariable)
{
    this->tableVariables[nomVariable].estUtilisee = true;
}










