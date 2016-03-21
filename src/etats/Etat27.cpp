#include "Etat27.h"
#include "Etat36.h"

int Etat27::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case EGAL_TERMINAL:
            automate->decalage(new Etat36, s);
            return CONTINUE;
        case NUM_TERMINAL:
        {
            // recuperation des erreurs
            Symbole* symboleOublie = new Symbole(EGAL_TERMINAL);
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat36);
            return CONTINUE;
        }
        default:
            return ERREUR;
    }
}
