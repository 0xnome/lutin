#include "TableDesSymboles.h"


bool TableDesSymboles::estUtilisee(std::string nomVariable) const
{
    //TODO
    return false;
}

bool TableDesSymboles::estConstante(std::string nomVariable) const
{
    //TODO
    return false;
}

bool TableDesSymboles::estInitialisee(std::string nomVariable) const
{
    //TODO
    return false;
}

bool TableDesSymboles::estDeclaree(std::string nomVariable) const
{
    return this->table.find(nomVariable) != this->table.end();
}







