#include "Etat21.h"
#include "Etat28.h"

int Etat21::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case NUM_TERMINAL:
            automate->decalage(new Etat28, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
