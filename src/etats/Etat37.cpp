#include "Etat37.h"
#include "Etat41.h"

int Etat37::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case FACTEUR:
        case CONST_TERMINAL:
        case IDENTIFICATEUR_FACTEUR:
        case EXPRESSION_PARENTHESEE:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat41);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
