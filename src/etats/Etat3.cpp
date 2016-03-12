#include "Etat3.h"
#include "Etat8.h"
#include "Etat9.h"

bool Etat3::transition(Automate* automate, Symbole* s)
{
    switch (*s){
        /*
        case AFFECTATION_CONSTANTE:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat8);
            return true;
        */
        case ID_TERMINAL:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat9);
            return automate->decalage();
        case VIRGULE_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
            // un affect se trouve dans la pile (normalement)
            automate->pushEtat(new Etat8);
            return automate->etatCourant()->transition(automate, s);
        default:
            return false;
    }
}
