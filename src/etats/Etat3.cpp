#include "Etat3.h"
#include "Etat8.h"
#include "Etat9.h"

bool Etat3::transition(Automate* automate, Symbole* s)
{
    switch (*s){
        case AFFECTATION_CONSTANTE:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat8());
            return true;
        case VAR_TERMINAL:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat9());
            automate->decalage();
            return true;
        default:
            return false;
    }
}
