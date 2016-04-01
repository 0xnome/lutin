#include "Etat11.h"
#include "Etat13.h"
#include "Etat12.h"
#include "PointVirguleTerminal.h"
#include "VirguleTerminal.h"

int Etat11::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat12, s);
            return CONTINUE;
        case VIRGULE_TERMINAL:
            automate->decalage(new Etat13, s);
            return CONTINUE;
            //recuperation des erreurs - point virgule oublie
        case VAR_TERMINAL:
        case CONST_TERMINAL:
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL :
        case FIN_PROGRAMME: {
            automate->erreurSyntaxique(s, "symbole ;");
            PointVirguleTerminal *symboleOublie = new PointVirguleTerminal(s->getLigne(), s->getColonne());
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat12);
            return CONTINUE;
        }

            // recuperation  des erreurs - oublie de virgule
        case ID_TERMINAL: {
            automate->erreurSyntaxique(s, "symbole ,");
            VirguleTerminal *symboleOublie = new VirguleTerminal(s->getLigne(), s->getColonne());
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat13);
            return CONTINUE;
        }
        default:
            return ERREUR;
    }
}
