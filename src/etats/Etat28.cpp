#include <NumTerminal.h>
#include <IdTerminal.h>
#include <AffectationConstante.h>
#include "Etat28.h"

bool Etat28::transition(Automate* automate, Symbole* s)
{
    NumTerminal* num;
    IdTerminal* id;
    AffectationConstante* affects;
    switch (*s){
        case VIRGULE_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
            num = (NumTerminal*) automate->popSymbole();
            automate->popSymbole();
            id = (IdTerminal*) automate->popSymbole();
            automate->popEtat(3);
            affects = new AffectationConstante(id, num);
            automate->etatCourant()->transition(automate, affects);
            // associer un identifiant de symbole à la classe, p-e en paramètre de la classe pour pouvoir modifier selon d'ou on vient
            return true;
        default:
            return false;
    }
}
