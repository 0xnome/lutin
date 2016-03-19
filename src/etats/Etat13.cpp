#include "Etat13.h"
#include "Etat14.h"

int Etat13::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case ID_TERMINAL:
            automate->decalage(new Etat14, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
