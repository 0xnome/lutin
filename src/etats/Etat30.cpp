#include <Facteur.h>
#include "Etat30.h"

int Etat30::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        // on lit un suivant de TERME
        case MULT_TERMINAL:
        case DIV_TERMINAL:
        case MOINS_TERMINAL:
        case PLUS_TERMINAL:
        case PARFER_TERMINAL:
        case POINT_VIRGULE_TERMINAL: {
            // SUIVANTS de TERME
            Facteur *facteur = (Facteur *) automate->popSymbole();
            automate->popEtat(1);
            // attention cast et passage en dynamique
            facteur->setDynamique(true);
            Terme *terme = (Terme *) facteur;
            return automate->etatCourant()->transition(automate, terme);
        }
        default:
            return ERREUR;
    }
}
