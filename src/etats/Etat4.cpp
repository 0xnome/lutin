#include "Etat4.h"
#include "Etat10.h"
#include "Etat11.h"

int Etat4::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case ID_TERMINAL:
            automate->decalage(new Etat10, s);
            return CONTINUE;
        case IDENTIFICATEUR_VARIABLE:
            // IDS
            automate->pushSymbole(s);
            automate->pushEtat(new Etat11);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
