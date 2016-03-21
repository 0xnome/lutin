#include "Etat11.h"
#include "Etat13.h"
#include "Etat12.h"

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
        case FIN_PROGRAMME:
        {
            Symbole* symboleOublie = new Symbole(POINT_VIRGULE_TERMINAL);
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat12);
            return CONTINUE;
        }

        // recuperation  des erreurs - oublie de virgule
        case ID_TERMINAL:
        {
            Symbole* symboleOublie = new Symbole(VIRGULE_TERMINAL);
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat13);
            return CONTINUE;
        }
        default:
            return ERREUR;
    }
}
