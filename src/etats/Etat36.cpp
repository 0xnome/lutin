#include "Etat36.h"
#include "Etat40.h"

bool Etat36::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case NUM_TERMINAL:
            automate->decalage(new Etat40, s);
            return CONTINUE;
        default:
            return false;
    }
}
