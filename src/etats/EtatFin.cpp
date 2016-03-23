#include "EtatFin.h"

int EtatFin::transition(Automate *automate, Symbole *s)
{
    switch (*s){
        case FIN_PROGRAMME: {
            Programme *programme = (Programme *) automate->popSymbole(false);
            automate->setProgramme(programme);
            delete s;
            return TERMINE;
        }
        default:
            return ERREUR;
    }
}
