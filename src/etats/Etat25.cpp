#include "Etat25.h"
#include "Etat23.h"
#include "Etat24.h"
#include "Etat35.h"

int Etat25::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case EXPRESSION_ADDITIVE:
            automate->decalage(new Etat23, s);
            return CONTINUE;

        case EXPRESSION_SOUSTRACTIVE:
            automate->decalage(new Etat24, s);
            return CONTINUE;

        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat35, s);
            return CONTINUE;

        default:
            return ERREUR;
    }
}
