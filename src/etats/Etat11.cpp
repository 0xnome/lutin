#include "Etat11.h"
#include "Etat13.h"
#include "Etat12.h"

int Etat11::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat12, s);
            return CONTINUE;
        case VIRGULE_TERMINAL:
            automate->decalage(new Etat13, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
