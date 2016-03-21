#include <IdentificateurVariable.h>
#include "Etat10.h"

int Etat10::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        // suivant de IDS
        case VIRGULE_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
        //recuperation des erreurs
        case VAR_TERMINAL:
        case CONST_TERMINAL:
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL :
        case ID_TERMINAL:
        case FIN_PROGRAMME:
        {
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
