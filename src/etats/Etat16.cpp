#include "Etat16.h"
#include "Etat44.h"

int Etat16::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat44, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
