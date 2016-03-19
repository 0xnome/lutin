#ifndef LUTIN_TABLEDESSYMBOLES_H
#define LUTIN_TABLEDESSYMBOLES_H

#include <unordered_map>
#include <string>


struct Entree
{
    bool estInitialisee;
    bool estUtilisee;
    int valeur;

};


class TableDesSymboles
{

public:

    TableDesSymboles();

    ~TableDesSymboles();

    /**
     * Ajoute une constante dans la table des symboles
     */
    void ajouterConstante(std::string nomConstante, int valeurConstante);

    /**
     * Ajoute une variable dans la table des symboles
     */
    void ajouterVariable(std::string nomVariable);

    /**
     * Set le booleen qui dit que la variable a été utilisée
     */
    void setVariableUtilisee(std::string nomVariable);

    /**
     * Set le booleen qui dit que la variable a été utilisee
     */
    void setConstanteUtilisee(std::string nomConstante);

    /**
     * Renvoie la valeur de la variable
     */
    int getVariableValeur(std::string nomVariable) const;

    /**
     * Renvoie la valeur de la constante
     */
    int getConstanteValeur(std::string nomConstante) const;


    /**
     * Retourne la valeur d'une variable ou d'une constante
     */
    int getValeur(std::string nom) const;


    Entree *getEntree(std::string nom) const;

    /**
     * Set la valeur de la variable à valeur
     */
    void setVariableValeur(std::string nomVariable, int valeur);

    /**
     * Regarde si la variable dont le nom passé en paramètre a été initialisée.
     * Suppose que la variable a déja été déclarée
     */
    bool estInitialisee(std::string nomVariable) const;

    /**
     * Regarde si la variable dont le nom passé en paramètre a utilisée au moins une fois dans le programme
     */
    bool estUtiliseeVariable(std::string nomVariable) const;

    /**
     * Regarde si la variable est dans la table des symboles
     */
    bool estDeclaree(std::string nomVariable) const;


    /* ------------ méthodes utilisées pour les tests -------------- */
    unsigned long getNbConstante() const;

    unsigned long getNbVariable() const;


private:
    std::unordered_map<std::string, Entree *> tableVariables;
    std::unordered_map<std::string, Entree *> tableConstantes;

    typedef std::unordered_map<std::string, Entree *>::iterator TableIterator;


};


#endif //LUTIN_TABLEDESSYMBOLES_H
