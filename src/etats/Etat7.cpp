#include "Etat7.h"
#include "Etat18.h"

int Etat7::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case AFFECT_TERMINAL:
            automate->decalage(new Etat18, s);
            return CONTINUE;

        case ID_TERMINAL:
        case NUM_TERMINAL:
        case PAROUV_TERMINAL:
        {
            Symbole* symboleOublie = new Symbole(AFFECT_TERMINAL);
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat18);
            return CONTINUE;
        }

        default:
            return ERREUR;
    }
}
