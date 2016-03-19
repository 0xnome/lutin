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
    case EXPRESSION_ADDITIVE:
    case EXPRESSION_SOUSTRACTIVE:
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
    case EXPRESSION_DIV:
        automate->decalage(new Etat38, s);
        return CONTINUE;

    case EXPRESSION_MULT:
        automate->decalage(new Etat37, s);
        return CONTINUE;

		default:
           return ERREUR;
   }
}
