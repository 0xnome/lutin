#include "TableDesSymboles.h"

using namespace std;

TableDesSymboles::TableDesSymboles()
{

}

TableDesSymboles::~TableDesSymboles()
{

}

bool TableDesSymboles::estUtiliseeVariable(string nomVariable) const
{
    return this->tableVariables.find(nomVariable)->second.estUtilisee;
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
    Entree constEntree =  {true, false, true, valeurConstante};
    this->tableConstantes[nomConstante] = constEntree;
}

void TableDesSymboles::ajouterVariable(std::string nomVariable)
{
    Entree varEntree = {false, false, false};
    this->tableVariables[nomVariable] = varEntree;
}

void TableDesSymboles::setVariableUtilisee(std::string nomVariable)
{
    auto iterator = this->tableVariables.find(nomVariable);
    if(iterator != this->tableVariables.end())
    {
        iterator->second.estUtilisee = true;
    }
}

void TableDesSymboles::setVariableValeur(std::string nomVariable, int valeur)
{
    auto iterator = this->tableVariables.find(nomVariable);
    if(iterator != this->tableVariables.end())
    {
        iterator->second.valeur = valeur;
        iterator->second.estInitialisee = true;
    }
}

void TableDesSymboles::setConstanteUtilisee(std::string nomConstante)
{
    auto iterator = this->tableConstantes.find(nomConstante);
    if(iterator != this->tableConstantes.end())
    {
        iterator->second.estUtilisee = true;
    }
}

int TableDesSymboles::getVariableValeur(std::string nomVariable) const
{
    auto iterator = this->tableVariables.find(nomVariable);
    return iterator->second.valeur;
}

int TableDesSymboles::getConstanteValeur(std::string nomConstante) const
{
    auto iterator = this->tableConstantes.find(nomConstante);
    return iterator->second.valeur;
}

unsigned long TableDesSymboles::getNbConstante() const
{
    return this->tableConstantes.size();
}

unsigned long TableDesSymboles::getNbVariable() const
{
    return this->tableVariables.size();
}

int TableDesSymboles::getValeur(std::string nom) const
{
    auto iterator = this->tableVariables.find(nom);

    if(iterator != this->tableVariables.end())
    {
        return iterator->second.valeur;
    }
    else
    {
        return this->tableConstantes.find(nom)->second.valeur;
    }
}




