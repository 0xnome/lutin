#ifndef LUTIN_SYMBOLE_H
#define LUTIN_SYMBOLE_H

#include <iostream>

enum SYMBOLES
{
	// Symboles non terminaux
    BLOCS_DECLARATION, // ???
    IDENTIFICATEUR_FACTEUR,
    BLOC_DECLARATIONS,
    DECLARATION_VARIABLE,
    DECLARATION_CONSTANTE,
    AFFECTATION_CONSTANTE,
    PROGRAMME,
    BLOC_INSTRUCTIONS,
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
};


#endif
