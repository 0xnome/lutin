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
        case POINT_VIRGULE_TERMINAL:
        //recuperation des erreurs
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL:
        case ID_TERMINAL:
        case FIN_PROGRAMME:
        {
            IdTerminal *id = (IdTerminal *) automate->popSymbole(false);
            automate->popEtat(1);
            Facteur* facteur = new IdentificateurFacteur(id);
            return automate->etatCourant()->transition(automate, facteur);
        }
        default:
            return ERREUR;
    }
}
