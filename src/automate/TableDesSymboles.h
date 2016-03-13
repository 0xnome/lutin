#ifndef LUTIN_TABLEDESSYMBOLES_H
#define LUTIN_TABLEDESSYMBOLES_H

#include <unordered_map>
#include <string>

struct Entree
{
    // TODO : rajouter la valeur de la variable
    bool estInitialisee;
    bool estConstante;
    bool estUtilisee;
};


class TableDesSymboles
{

public:


    TableDesSymboles()
    { }


    virtual ~TableDesSymboles()
    { }

    /**
     * Regarde si la variable dont le nom passé en paramètre a été initialisée
     */
    bool estInitialisee(std::string nomVariable) const;

    /**
     * Regarde si la variable dont le nom passé en paramètre est une constante
     */
    bool estConstante(std::string nomVariable) const;

    /**
     * Regarde si la variable dont le nom passé en paramètre a utilisée au moins une fois dans le programme
     */
    bool estUtilisee(std::string nomVariable) const;

    /**
     * Regarde si la variable est dans la table des symboles
     */
    bool estDeclaree(std::string nomVariable) const;

private:
    std::unordered_map<std::string, Entree> table;

};


#endif //LUTIN_TABLEDESSYMBOLES_H
