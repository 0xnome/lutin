#include "Etat9.h"
#include "Etat21.h"
#include "EgalTerminal.h"

int Etat9::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case EGAL_TERMINAL:
            automate->decalage(new Etat21, s);
            return CONTINUE;
        // recuperation des erreurs
        case NUM_TERMINAL:
        {
            EgalTerminal* symboleOublie = new EgalTerminal(s->getLigne(), s->getColonne());
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat21);
            return CONTINUE;
        }
        default:
            return ERREUR;
    }
}
