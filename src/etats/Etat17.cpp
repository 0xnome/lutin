#include "Etat17.h"
#include "Terme.h"

int Etat17::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case POINT_VIRGULE_TERMINAL:
        case PARFER_TERMINAL:
        case EXPRESSION_SOUSTRACTIVE:
        case EXPRESSION_ADDITIVE:
        {
            Terme * terme = (Terme*) automate->popSymbole();
            automate->popEtat(1);
            Expression* expression = (Expression*) terme;

            return automate->etatCourant()->transition(automate, expression);
        }
        default:
            return ERREUR;
    }
}
