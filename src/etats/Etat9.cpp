#include "Etat9.h"
#include "Etat21.h"

int Etat9::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case EGAL_TERMINAL:
            automate->decalage(new Etat21, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
