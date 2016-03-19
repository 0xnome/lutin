#include "Etat7.h"
#include "Etat18.h"

int Etat7::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case AFFECT_TERMINAL:
            automate->decalage(new Etat18, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
