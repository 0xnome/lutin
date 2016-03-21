#include "TableDesSymboles.h"


using namespace std;

TableDesSymboles::TableDesSymboles()
{

}

TableDesSymboles::~TableDesSymboles()
{
    resetTableDesSymboles();
}

bool TableDesSymboles::estUtiliseeVariable(string nomVariable) const
{
    return this->tableVariables.find(nomVariable)->second->estUtilisee;
}

bool TableDesSymboles::estInitialisee(string nomVariable) const
{
    return this->tableVariables.find(nomVariable)->second->estInitialisee;
}

bool TableDesSymboles::estDeclaree(string nomVariable) const
{
    return this->tableVariables.find(nomVariable) != this->tableVariables.end() ||
           this->tableConstantes.find(nomVariable) != this->tableConstantes.end();
}

void TableDesSymboles::ajouterConstante(std::string constante, unsigned ligne, unsigned colonne, int valeurConstante)
{
    Entree *constEntree = new Entree;
    int *val = new int(valeurConstante);
    *constEntree = {true, false, val, ligne, colonne};
    pair<TableIterator, bool> result = this->tableConstantes.insert({constante, constEntree});
    if(!result.second)
    {
        delete (constEntree);
    }

}

void TableDesSymboles::ajouterVariable(std::string variable, unsigned ligne, unsigned colonne)
{
    Entree *varEntree = new Entree;
    *varEntree = {false, false,};
    varEntree->ligne = ligne;
    varEntree->colonne = colonne;
    pair<TableIterator, bool> result = this->tableVariables.insert({variable, varEntree});
    if(!result.second)
    {
        delete (varEntree);
    }

}


void TableDesSymboles::setVariableUtilisee(std::string nomVariable)
{
    auto iterator = this->tableVariables.find(nomVariable);
    if(iterator != this->tableVariables.end())
    {
        iterator->second->estUtilisee = true;
    }
}

void TableDesSymboles::setVariableValeur(std::string nomVariable, int valeur)
{
    auto iterator = this->tableVariables.find(nomVariable);
    if(iterator != this->tableVariables.end())
    {
        iterator->second->valeur = new int(valeur);
        iterator->second->estInitialisee = true;
    }
}

void TableDesSymboles::setConstanteUtilisee(std::string nomConstante)
{
    auto iterator = this->tableConstantes.find(nomConstante);
    if(iterator != this->tableConstantes.end())
    {
        iterator->second->estUtilisee = true;
    }
}

int *TableDesSymboles::getVariableValeur(std::string nomVariable) const
{
    auto iterator = this->tableVariables.find(nomVariable);
    return iterator->second->valeur;
}

int *TableDesSymboles::getConstanteValeur(std::string nomConstante) const
{
    auto iterator = this->tableConstantes.find(nomConstante);
    return iterator->second->valeur;
}

unsigned long TableDesSymboles::getNbConstante() const
{
    return this->tableConstantes.size();
}

unsigned long TableDesSymboles::getNbVariable() const
{
    return this->tableVariables.size();
}

int *TableDesSymboles::getValeur(std::string nom) const
{
    auto iterator = this->tableVariables.find(nom);

    if(iterator != this->tableVariables.end())
    {
        return iterator->second->valeur;
    }
    else
    {
        return this->tableConstantes.find(nom)->second->valeur;
    }
}

Entree *TableDesSymboles::getEntree(std::string nom) const
{
    auto iteratorTableConstante = this->tableConstantes.find(nom);
    auto iteratorTableVariable = this->tableVariables.find(nom);


    if(iteratorTableConstante != this->tableConstantes.end())
    {
        return iteratorTableConstante->second;
    }
    else if(iteratorTableVariable != this->tableVariables.end())
    {
        return iteratorTableVariable->second;
    }
    else
    {
        return nullptr;
    }
}

bool TableDesSymboles::estConstante(std::string nom) const
{
    return this->tableConstantes.find(nom) != this->tableConstantes.end();
}


void TableDesSymboles::setInitialisee(std::string nom)
{
    auto iterator = this->tableVariables.find(nom);
    if(iterator != this->tableVariables.end())
    {
        iterator->second->estInitialisee = true;
        iterator->second->valeur = nullptr;
    }
}

void TableDesSymboles::resetTableDesSymboles()
{
    for (auto it = this->tableConstantes.begin(); it != this->tableConstantes.end(); ++it)
    {
        delete it->second->valeur;
        it->second->valeur = nullptr;
        delete it->second;
    }


    for (auto it = this->tableVariables.begin(); it != this->tableVariables.end(); ++it)
    {
        delete it->second->valeur;
        it->second->valeur = nullptr;
        delete it->second;
    }

    // TODO : faire des clear
}


