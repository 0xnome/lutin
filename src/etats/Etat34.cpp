#include "Etat34.h"
#include "Etat37.h"
#include "Etat38.h"
#include "Expression.h"
#include "Terme.h"
#include "ExpressionSoustractive.h"

int Etat34::transition(Automate *automate, Symbole *s) {
    switch (*s) {

        // suivant de exp
        case PLUS_TERMINAL:
        case MOINS_TERMINAL:
        case PARFER_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
            //recuperation des erreurs
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL:
        case ID_TERMINAL:
        case FIN_PROGRAMME: {
            Terme *terme = (Terme *) automate->popSymbole(false);
            automate->popSymbole(true); // sous
            Expression *expr = (Expression *) automate->popSymbole(false);

            automate->popEtat(3);

            ExpressionSoustractive *expression = new ExpressionSoustractive(terme, expr);

            return automate->etatCourant()->transition(automate, expression);
        }
        case DIV_TERMINAL:
            automate->decalage(new Etat38, s);
            return CONTINUE;

        case MULT_TERMINAL:
            automate->decalage(new Etat37, s);
            return CONTINUE;

        default:
            return ERREUR;
    }
}
