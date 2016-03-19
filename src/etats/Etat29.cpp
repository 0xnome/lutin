#include <Terme.h>
#include <ExpressionAdditive.h>
#include "Etat29.h"
#include "Etat37.h"
#include "Etat38.h"

int Etat29::transition(Automate *automate, Symbole *s)
{
    switch (*s)
    {
        //  suivant de exp
        case PLUS_TERMINAL:
        case MOINS_TERMINAL:
        case PARFER_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
        {
            Terme *terme = (Terme *) automate->popSymbole(); // on recupère la terme
            automate->popSymbole(); // on pop le add
            Expression *expression = (Expression *) automate->popSymbole();

            ExpressionAdditive *expressionAdditive = new ExpressionAdditive(terme, expression);
            automate->popEtat(3);

            return automate->etatCourant()->transition(automate, expressionAdditive);
        }

        case MULT_TERMINAL:
            automate->decalage(new Etat37,s);
            return CONTINUE;

        case DIV_TERMINAL:
            automate->decalage(new Etat38,s);
            return CONTINUE;

        default:
            return ERREUR;
    }
}
