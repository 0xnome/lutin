#include "Etat6.h"
#include "Etat31.h"
#include "Etat30.h"
#include "Etat17.h"
#include "Etat16.h"


int Etat6::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case ID_TERMINAL:
            automate->decalage(new Etat31, s);
            return CONTINUE;
        case FACTEUR:
            automate->decalage(new Etat30, s);
            return CONTINUE;
        case TERME:
            automate->decalage(new Etat17, s);
            return CONTINUE;
        case EXPRESSION:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat16);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
