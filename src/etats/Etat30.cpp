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
        case POINT_VIRGULE_TERMINAL:
        //recuperation des erreurs
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL:
        case ID_TERMINAL:
        case FIN_PROGRAMME:
        {
            // SUIVANTS de TERME
            Facteur *facteur = (Facteur *) automate->popSymbole(false);
            automate->popEtat(1);
            // attention cast et passage en dynamique
            facteur->setStatiqueClasse(TERME);
            Terme *terme = (Terme *) facteur;
            return automate->etatCourant()->transition(automate, terme);
        }
        default:
            return ERREUR;
    }
}
