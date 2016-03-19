#include "Etat34.h"
#include "Etat37.h"
#include "Etat38.h"
#include "Expression.h"
#include "Terme.h"
#include "ExpressionSoustractive.h"

int Etat34::transition(Automate *automate, Symbole *s)
{
   switch (*s){

    // suivant de exp
    case PLUS_TERMINAL:
    case MOINS_TERMINAL:
    case PARFER_TERMINAL:
    case POINT_VIRGULE_TERMINAL:
    {
        Terme* terme = (Terme *) automate->popSymbole();
        automate->popSymbole(); // sous
        Expression* expr = (Expression *) automate->popSymbole();

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
