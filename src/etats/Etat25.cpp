#include "Etat25.h"
#include "Etat23.h"
#include "Etat24.h"
#include "Etat35.h"
#include "PointVirguleTerminal.h"

int Etat25::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case PLUS_TERMINAL:
            automate->decalage(new Etat23, s);
            return CONTINUE;

        case MOINS_TERMINAL:
            automate->decalage(new Etat24, s);
            return CONTINUE;

        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat35, s);
            return CONTINUE;
            // recuperation des erreurs
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL:
        case ID_TERMINAL:
        case FIN_PROGRAMME: {
            automate->erreurSyntaxique(s, "symbole ;");
            PointVirguleTerminal *symboleOublie = new PointVirguleTerminal(s->getLigne(), s->getColonne());
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat35);
            return CONTINUE;
        }

        default:
            return ERREUR;
    }
}
