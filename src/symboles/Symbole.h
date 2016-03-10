#ifndef LUTIN_SYMBOLE_H
#define LUTIN_SYMBOLE_H

#include <iostream>

enum SYMBOLES
{
    // Symboles non terminaux
    PROGRAMME,                  //0

    // Partie instruction
    BLOC_INSTRUCTION,           //1

    INSTRUCTION_LECTURE,        //2
    INSTRUCTION_ECRITURE,       //3
    INSTRUCTION_AFFECTATION,    //4

    EXPRESSION,                 //5
    EXPRESSION_ADDITIVE,        //6
    EXPRESSION_SOUSTRACTIVE,    //7
    EXPRESSION_MULT,            //8
    EXPRESSION_DIV,             //9

    TERME,                      //10
    FACTEUR,                    //11
    EXPRESSION_PARENTHESEE,     //12
    CONSTANTE_NUMERIQUE,        //13
    IDENTIFICATEUR_FACTEUR,     //14

    // Partie déclaration
    BLOC_DECLARATION,           //15

    IDENTIFICATEUR_VARIABLE,    //16
    DECLARATION_VARIABLE,       //17

    AFFECTATION_CONSTANTE,      //18
    DECLARATION_CONSTANTE,      //19


    // Symboles terminaux
    ID_TERMINAL,                //20
    NUM_TERMINAL,               //21
    VAR_TERMINAL,               //22
    CONST_TERMINAL,             //23
    LIRE_TERMINAL,              //24
    ECRIRE_TERMINAL,            //25
    PLUS_TERMINAL,              //26
    MOINS_TERMINAL,             //27
    MULT_TERMINAL,              //28
    DIV_TERMINAL,               //29
    VIRGULE_TERMINAL,           //30
    POINT_VIRGULE_TERMINAL,     //31
    EGAL_TERMINAL,              //32
    AFFECT_TERMINAL,            //33
    PAROUV_TERMINAL,            //34
    PARFER_TERMINAL,            //35



    // Autres symboles
    FIN_PROGRAMME,              //36
    ERREUR_LEXICALE             //37
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


    friend std::ostream &operator<<(std::ostream &os, const Symbole &symbole)
    {
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
