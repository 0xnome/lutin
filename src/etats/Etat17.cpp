#include <Terme.h>
#include "Etat17.h"

int Etat17::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case PARFER_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
        case PLUS_TERMINAL:
        case MOINS_TERMINAL:{
            // les SUIVANTS de EXPRESSION
            Terme *terme = (Terme *) automate->popSymbole();
            automate->popEtat(1);
            // attention cast et passage en dynamique
            terme->setDynamique(true);
            Expression *expression = (Expression *) terme;
            automate->etatCourant()->transition(automate, expression);
        }
        default:
            return ERREUR;
    }
}
