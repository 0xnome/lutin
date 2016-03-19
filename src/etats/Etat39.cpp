#include "Etat39.h"
#include "Etat43.h"
#include "Etat23.h"
#include "Etat24.h"


int Etat39::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case PARFER_TERMINAL:
            automate->decalage(new Etat43, s);
            return CONTINUE;

        case PLUS_TERMINAL:
            automate->decalage(new Etat23, s);
            return CONTINUE;

        case MOINS_TERMINAL:
            automate->decalage(new Etat24, s);
            return CONTINUE;

        default:
            return ERREUR;
    }
}
