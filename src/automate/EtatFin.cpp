#include "EtatFin.h"

bool EtatFin::transition(Automate* automate, Symbole* s)
{
    switch (*s){
        case FIN_PROGRAMME: {
            Programme *programme = (Programme *) automate->popSymbole();
            automate->setProgramme(programme);
            return true;
        }
        default:
            return false;
    }
}
