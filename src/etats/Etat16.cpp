#include "Etat16.h"
#include "Etat44.h"
#include "Etat23.h"

int Etat16::transition(Automate *automate, Symbole *s)
{
    switch (*s)
    {
        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat44, s);
            return CONTINUE;
        case PLUS_TERMINAL:
            automate->decalage(new Etat23, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
