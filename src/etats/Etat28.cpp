#include <NumTerminal.h>
#include <IdTerminal.h>
#include <AffectationConstante.h>
#include "Etat28.h"

bool Etat28::transition(Automate* automate, Symbole* s)
{
    switch (*s) {
        case VIRGULE_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
        {
            NumTerminal *num = (NumTerminal *) automate->popSymbole();
            automate->popSymbole(); // pop du EGAL_TERMINAL
            IdTerminal *id = (IdTerminal *) automate->popSymbole();
            automate->popEtat(3);   // pop de 3 symboles, donc pop de 3 Etats

            // Etat courant : Etat3
            AffectationConstante *affects = new AffectationConstante(id, num);
            automate->pushSymbole(affects);

            // associer un identifiant de symbole à la classe, p-e en paramètre de la classe pour pouvoir modifier selon d'ou on vient
            return automate->etatCourant()->transition(automate, s);
        }
        default:
            return false;
    }
}
