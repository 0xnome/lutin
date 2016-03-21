#include "Etat8.h"
#include "Etat19.h"
#include "Etat20.h"

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
        case FIN_PROGRAMME:
        {
            Symbole* symboleOublie = new Symbole(POINT_VIRGULE_TERMINAL);
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat19);
            return CONTINUE;
        }

        case ID_TERMINAL:
        {
            Symbole* symboleOublie = new Symbole(VIRGULE_TERMINAL);
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat20);
            return CONTINUE;
        }
        default:
            return ERREUR;
    }
}
