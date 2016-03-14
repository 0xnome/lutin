#include "Etat27.h"
#include "Etat36.h"

int Etat27::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case EGAL_TERMINAL:
            automate->decalage(new Etat36, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
