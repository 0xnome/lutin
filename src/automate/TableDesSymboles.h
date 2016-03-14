#ifndef LUTIN_TABLEDESSYMBOLES_H
#define LUTIN_TABLEDESSYMBOLES_H

#include <unordered_map>
#include <string>

struct Entree
{
    // TODO : rajouter la valeur de la variable
    bool estInitialisee;
    bool estUtilisee;
    int valeur;
};


class TableDesSymboles
{

public:

    TableDesSymboles();

    ~TableDesSymboles();

    void ajouterConstante(std::string nomConstante, int valeurConstante);

    void ajouterVariable(std::string nomConstante);

    void setVariableUtilisee(std::string nomVariable);

    /**
     * Regarde si la variable dont le nom passé en paramètre a été initialisée
     */
    bool estInitialisee(std::string nomVariable) const;

    /**
     * Regarde si la variable dont le nom passé en paramètre a utilisée au moins une fois dans le programme
     */
    bool estUtilisee(std::string nomVariable) const;

    /**
     * Regarde si la variable est dans la table des symboles
     */
    bool estDeclaree(std::string nomVariable) const;


private:
    std::unordered_map<std::string, Entree> tableVariables;
    std::unordered_map<std::string, Entree> tableConstantes;

};


#endif //LUTIN_TABLEDESSYMBOLES_H
