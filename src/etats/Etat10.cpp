#include <IdentificateurVariable.h>
#include "Etat10.h"

int Etat10::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case VIRGULE_TERMINAL:
        case POINT_VIRGULE_TERMINAL: {
            // suivants de IDS
            IdTerminal *idTerminal = (IdTerminal *) automate->popSymbole();
            automate->popEtat(1);

            IdentificateurVariable *ids = new IdentificateurVariable(idTerminal);

            return automate->etatCourant()->transition(automate, ids);
        }
        default:
            return ERREUR;
    }
}
