#include "Etat15.h"
#include "Etat22.h"

int Etat15::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat22, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
