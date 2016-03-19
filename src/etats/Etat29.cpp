#include <Terme.h>
#include <ExpressionAdditive.h>
#include "Etat29.h"

int Etat29::transition(Automate *automate, Symbole *s)
{
    switch (*s)
    {

        case EXPRESSION_ADDITIVE:
        case EXPRESSION_SOUSTRACTIVE:
        case PARFER_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
        {
            Terme *terme = (Terme *) automate->popSymbole(); // on recupère la terme
            automate->popSymbole(); // on pop le add
            Expression *expression = (Expression *) automate->popSymbole();

            ExpressionAdditive *expressionAdditive = new ExpressionAdditive(terme, expression);
            automate->popEtat(3);

            automate->etatCourant()->transition(automate, expressionAdditive);
            return CONTINUE;
        }

        default:
            return ERREUR;
    }
}
