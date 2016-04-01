#include "Etat7.h"
#include "Etat18.h"
#include "AffectTerminal.h"

int Etat7::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case AFFECT_TERMINAL:
            automate->decalage(new Etat18, s);
            return CONTINUE;

        case ID_TERMINAL:
        case NUM_TERMINAL:
        case PAROUV_TERMINAL: {
            automate->erreurSyntaxique(s, "operateur :=");
            AffectTerminal *symboleOublie = new AffectTerminal(s->getLigne(), s->getColonne());
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat18);
            return CONTINUE;
        }

        default:
            return ERREUR;
    }
}
