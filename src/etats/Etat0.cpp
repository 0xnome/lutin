#include "Etat0.h"
#include "EtatFin.h"
#include "Etat1.h"

bool Etat0::transition(Automate* automate, Symbole* s)
{
    switch (*s){
        case PROGRAMME:
            automate->pushSymbole(s);
            automate->pushEtat(new EtatFin());
            return true;
        case BLOC_DECLARATION:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat1());
            return true;
        default:
            return false;
    }
}
