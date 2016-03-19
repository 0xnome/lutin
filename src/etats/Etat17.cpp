#include <Terme.h>
#include "Etat17.h"
#include "Terme.h"

int Etat17::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case PARFER_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
        case PLUS_TERMINAL:
        case MOINS_TERMINAL:{
            // les SUIVANTS de EXPRESSION
            Terme *terme = (Terme *) automate->popSymbole();
            automate->popEtat(1);
            // attention cast et passage en statique
            terme->setStatiqueClasse(EXPRESSION);
            Expression *expression = (Expression *) terme;
            return automate->etatCourant()->transition(automate, expression);
        }
        default:
            return ERREUR;
    }
}
