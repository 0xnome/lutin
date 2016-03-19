#include "Etat23.h"
#include "Etat29.h"
#include "Etat31.h"

int Etat23::transition(Automate *automate, Symbole *s)
{
    switch (*s)
    {
        case ID_TERMINAL:
            automate->decalage(new Etat31, s);
            return CONTINUE;
        case TERME:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat29);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
