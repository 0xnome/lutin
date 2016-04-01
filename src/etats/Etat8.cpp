#include "Etat8.h"
#include "Etat19.h"
#include "Etat20.h"
#include "PointVirguleTerminal.h"
#include "VirguleTerminal.h"

int Etat8::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat19, s);
            return CONTINUE;
        case VIRGULE_TERMINAL:
            automate->decalage(new Etat20, s);
            return CONTINUE;
            //recuperation des erreurs
        case VAR_TERMINAL:
        case CONST_TERMINAL:
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL :
        case FIN_PROGRAMME: {
            automate->erreurSyntaxique(s, "symbole ;");
            PointVirguleTerminal *symboleOublie = new PointVirguleTerminal(s->getLigne(), s->getColonne());
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat19);
            return CONTINUE;
        }

        case ID_TERMINAL: {
            VirguleTerminal *symboleOublie = new VirguleTerminal(s->getLigne(), s->getColonne());
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat20);
            return CONTINUE;
        }
        default:
            return ERREUR;
    }
}
