#ifndef LUTIN_SYMBOLE_H
#define LUTIN_SYMBOLE_H

#include <iostream>

enum SYMBOLES
{
	// Symboles non terminaux
    BLOC_DECLARATION, // ???
    IDENTIFICATEUR_FACTEUR,
    DECLARATION_VARIABLE,
    DECLARATION_CONSTANTE,
    AFFECTATION_CONSTANTE,
    PROGRAMME,
    BLOC_INSTRUCTION,
    INSTRUCTION_LECTURE,
    INSTRUCTION_ECRITURE,
    INSTRUCTION_AFFECTATION,
    EXPRESSION,
    EXPRESSION_ADDITIVE,
    EXPRESSION_SOUSTRACTIVE,
    TERME,
    EXPRESSION_MULT,
    EXPRESSION_DIV,
    FACTEUR,
    EXPRESSION_PARENTHESEE,
    CONSTANTE_NUMERIQUE,
    
    // Symboles terminaux
    CONST_TERMINAL,
    VAR_TERMINAL,
    VIRGULE,
    POINT_VIRGULE
};


class Symbole
{
protected:
    int identifiant;
public:
    Symbole(int id) : identifiant(id)
    { }

    virtual ~Symbole()
    { }


    friend std::ostream &operator<<(std::ostream& os, const Symbole & symbole) {
        return os << symbole.identifiant;
    }

    operator int() const
    { return identifiant; }

    /**
     * Execute le programme de manière interactive (option -e)
     */
    virtual void executer()
    { }

    /**
     * Affiche la représentation en memoire du programme (option -p)
     * Les éventuelles erreurs sont affichées
     * TODO:  parcourir les blocs déclarations et instructions pour afficher leur contenu
     */
    virtual void afficher()
    { }

    /**
     * Analyse statique du programme afin d'en extraire les erreurs (option -a)
     *
     * TODO: erreurs à vérifier
     *  - Les variables et constantes utilisées dans la partie intructions sont bien dans la déclaration
     *  - var déclarées mais non initialisées
     *  - Mettre des warnings si elles ne sont pas utilisées
     *  - Duplications ou conflits de noms de variables et constantes
     *  - mots clefs interdits (var, const, ecrire et lire) à réflechir...
     *  - modification d'une constante
     */
    virtual void analyser()
    { }


    /**
     * Transfome le programme et le simplfie (option -o)
    */
    virtual void optimiser()
    { }


};


#endif
