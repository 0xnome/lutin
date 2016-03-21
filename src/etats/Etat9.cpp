#include "Etat9.h"
#include "Etat21.h"

int Etat9::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case EGAL_TERMINAL:
            automate->decalage(new Etat21, s);
            return CONTINUE;
        // recuperation des erreurs
        case NUM_TERMINAL:
        {
            Symbole* symboleOublie = new Symbole(EGAL_TERMINAL);
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat21);
            return CONTINUE;
        }
        default:
            return ERREUR;
    }
}
