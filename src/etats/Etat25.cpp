#include "Etat25.h"
#include "Etat35.h"

int Etat25::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat35, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
