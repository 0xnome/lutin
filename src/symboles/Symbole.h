#ifndef LUTIN_SYMBOLE_H
#define LUTIN_SYMBOLE_H

#include <iostream>
#include "TableDesSymboles.h"

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

class TableDesSymboles;

class Symbole
{
protected:
    int identifiant;
    unsigned ligne;
    unsigned colonne;
public:
    static std::string getName(Symbole *s)
    {
        switch (*s)
        {
            case PROGRAMME :
                return "PROGRAMME";
            case BLOC_INSTRUCTION :
                return "BLOC_INSTRUCTION";
            case INSTRUCTION_LECTURE :
                return "INSTRUCTION_LECTURE";
            case INSTRUCTION_ECRITURE :
                return "INSTRUCTION_ECRITURE";
            case INSTRUCTION_AFFECTATION :
                return "INSTRUCTION_AFFECTATION";
            case EXPRESSION :
                return "EXPRESSION";
            case EXPRESSION_ADDITIVE :
                return "EXPRESSION_ADDITIVE";
            case EXPRESSION_SOUSTRACTIVE :
                return "EXPRESSION_SOUSTRACTIVE";
            case EXPRESSION_MULT :
                return "EXPRESSION_MULT";
            case EXPRESSION_DIV :
                return "EXPRESSION_DIV";
            case TERME :
                return "TERME";
            case FACTEUR :
                return "FACTEUR";
            case EXPRESSION_PARENTHESEE :
                return "EXPRESSION_PARENTHESEE";
            case CONSTANTE_NUMERIQUE :
                return "CONSTANTE_NUMERIQUE";
            case IDENTIFICATEUR_FACTEUR :
                return "IDENTIFICATEUR_FACTEUR";
            case BLOC_DECLARATION :
                return "BLOC_DECLARATION";
            case IDENTIFICATEUR_VARIABLE :
                return "IDENTIFICATEUR_VARIABLE";
            case DECLARATION_VARIABLE :
                return "DECLARATION_VARIABLE";
            case AFFECTATION_CONSTANTE :
                return "AFFECTATION_CONSTANTE";
            case DECLARATION_CONSTANTE :
                return "DECLARATION_CONSTANTE";
            case ID_TERMINAL :
                return "ID_TERMINAL";
            case NUM_TERMINAL :
                return "NUM_TERMINAL";
            case VAR_TERMINAL :
                return "VAR_TERMINAL";
            case CONST_TERMINAL :
                return "CONST_TERMINAL";
            case LIRE_TERMINAL :
                return "LIRE_TERMINAL";
            case ECRIRE_TERMINAL :
                return "ECRIRE_TERMINAL";
            case PLUS_TERMINAL :
                return "PLUS_TERMINAL";
            case MOINS_TERMINAL :
                return "MOINS_TERMINAL";
            case MULT_TERMINAL :
                return "MULT_TERMINAL";
            case DIV_TERMINAL :
                return "DIV_TERMINAL";
            case VIRGULE_TERMINAL :
                return "VIRGULE_TERMINAL";
            case POINT_VIRGULE_TERMINAL :
                return "POINT_VIRGULE_TERMINAL";
            case EGAL_TERMINAL :
                return "EGAL_TERMINAL";
            case AFFECT_TERMINAL :
                return "AFFECT_TERMINAL";
            case PAROUV_TERMINAL :
                return "PAROUV_TERMINAL";
            case PARFER_TERMINAL :
                return "PARFER_TERMINAL";
            case FIN_PROGRAMME :
                return "FIN_PROGRAMME";
            case ERREUR_LEXICALE  :
                return "ERREUR_LEXICALE ";
            default:
                return "SYMBOLE_INCONNU";
        }
    }

    Symbole(int id) : identifiant(id), ligne(0), colonne(0)
    { };

    Symbole(int id, unsigned ligne, unsigned colonne) : identifiant(id), ligne(ligne), colonne(colonne)
    { };

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
    virtual void executer(TableDesSymboles *tableDesSymboles)
    { }

    /**
     * Affiche la représentation en memoire du programme (option -p)
     * Les éventuelles erreurs sont affichées
     */
    virtual void afficher()
    { }

    unsigned getLigne()
    { return ligne; }

    unsigned getColonne()
    { return colonne; }

    /**
     * Analyse statique du programme afin d'en extraire les erreurs (option -a)
     *
     * TODO: erreurs à vérifier
     *  - Les variables et constantes utilisées dans la partie intruction sont bien dans la déclaration [OK]
     *  - var déclarées mais non initialisées
     *  - Mettre des warnings si elles ne sont pas utilisées
     *  - Duplications ou conflits de noms de variables et constantes [OK]
     *  - mots clefs interdits (var, const, ecrire et lire) à réflechir...
     *  - modification d'une constante [OK]
     */
    virtual void analyser(TableDesSymboles *tableDesSymboles)
    { }


    /**
     * Transfome le programme et le simplfie (option -o)
    */
    virtual void optimiser(TableDesSymboles *tableDesSymboles)
    { }


};


#endif
