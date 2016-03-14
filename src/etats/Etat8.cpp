#include "Etat8.h"
#include "Etat19.h"
#include "Etat20.h"

int Etat8::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat19, s);
            return CONTINUE;
        case VIRGULE_TERMINAL:
            automate->decalage(new Etat20, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
