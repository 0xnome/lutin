#include "Etat43.h"
#include "Expression.h"
#include "ExpressionParenthesee.h"


int Etat43::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        // suivant de facteur
        case EXPRESSION_MULT:
        case EXPRESSION_DIV:
        case EXPRESSION_ADDITIVE:
        case EXPRESSION_SOUSTRACTIVE:
        case PARFER_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
        {
          automate->popSymbole(); //parfer
          Expression * expr = (Expression*) automate->popSymbole();
          automate->popSymbole(); //parouv
          automate->popEtat(3);

          ExpressionParenthesee* expressionParenthesee = new ExpressionParenthesee(expr);
          return automate->etatCourant()->transition(automate, expressionParenthesee);
        }
        default:
            return ERREUR;
    }
}
