#include <IdTerminal.h>
#include <IdentificateurFacteur.h>
#include "Etat31.h"

int Etat31::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        // suivants de FACTEUR
        case PARFER_TERMINAL:
        case MULT_TERMINAL:
        case DIV_TERMINAL:
        case MOINS_TERMINAL:
        case PLUS_TERMINAL:
        case POINT_VIRGULE_TERMINAL: {
            IdTerminal* id = (IdTerminal*)automate->popSymbole();
            automate->popEtat(1);
            Facteur* facteur = new IdentificateurFacteur(id);
            automate->etatCourant()->transition(automate, facteur);
            return CONTINUE;
        }
        default:
            return ERREUR;
    }
}
