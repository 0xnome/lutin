#include "Etat32.h"
#include "NumTerminal.h"
#include "Facteur.h"
#include "ConstanteNumerique.h"

int Etat32::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        // suivant de Facteur
        case MULT_TERMINAL:
        case DIV_TERMINAL:
        case MOINS_TERMINAL:
        case PLUS_TERMINAL:
        case PARFER_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
        {
            NumTerminal* numTerminal = (NumTerminal*) automate->popSymbole();
            automate->popEtat(1);

            ConstanteNumerique * constanteNumerique = new ConstanteNumerique(numTerminal);
            return automate->etatCourant()->transition(automate, constanteNumerique);
        }
        default:
            return ERREUR;
    }
}
