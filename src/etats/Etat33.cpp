#include "Etat33.h"
#include "Etat31.h"
#include "Etat32.h"

int Etat33::transition(Automate *automate, Symbole *s)
{
    switch (*s)
    {
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
