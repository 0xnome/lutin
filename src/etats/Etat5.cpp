#include "Etat5.h"
#include "Etat15.h"

int Etat5::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case ID_TERMINAL:
            automate->decalage(new Etat15, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
