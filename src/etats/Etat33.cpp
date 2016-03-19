#include "Etat33.h"
#include "Etat31.h"
#include "Etat32.h"
#include "Etat39.h"
#include "Etat17.h"

int Etat33::transition(Automate *automate, Symbole *s)
{
    switch (*s)
    {
        case EXPRESSION:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat39);
            return CONTINUE;
        case TERME:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat17);
            return CONTINUE;

        case ID_TERMINAL :
            automate->decalage(new Etat31, s);
            return CONTINUE;
        case NUM_TERMINAL:
            automate->decalage(new Etat32, s);
            return CONTINUE;
        case PAROUV_TERMINAL:
            automate->decalage(new Etat33, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
