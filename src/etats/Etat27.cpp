#include "Etat27.h"
#include "Etat36.h"
#include "EgalTerminal.h"

int Etat27::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case EGAL_TERMINAL:
            automate->decalage(new Etat36, s);
            return CONTINUE;
        case NUM_TERMINAL: {
            // recuperation des erreurs
            automate->erreurSyntaxique(s, "operateur =");
            EgalTerminal *symboleOublie = new EgalTerminal(s->getLigne(), s->getColonne());
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat36);
            return CONTINUE;
        }
        default:
            return ERREUR;
    }
}
