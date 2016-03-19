#include "Etat38.h"
#include "Etat42.h"
#include "Etat31.h"

int Etat38::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case FACTEUR:
        case CONST_TERMINAL:
        case IDENTIFICATEUR_FACTEUR:
        case EXPRESSION_PARENTHESEE:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat42);
        case NUM_TERMINAL:
            automate->decalage(new Etat31, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
