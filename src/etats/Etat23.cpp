#include "Etat23.h"
#include "Etat29.h"
#include "Etat30.h"
#include "Etat31.h"
#include "Etat32.h"
#include "Etat33.h"
#include <Expression.h>

int Etat23::transition(Automate *automate, Symbole *s)
{
    // ATTENTION CONFLIT DE TYPE POTENTIEL DANS LES CASES
    int intS = (int)*s;
    switch (intS){
        case EXPRESSION:
        case EXPRESSION_ADDITIVE:
        case EXPRESSION_SOUSTRACTIVE:
        case TERME:
        case EXPRESSION_MULT:
        case EXPRESSION_DIV:
        case FACTEUR:
        case CONSTANTE_NUMERIQUE:
        case IDENTIFICATEUR_FACTEUR:
        case EXPRESSION_PARENTHESEE:
            intS = ((Expression*)s)->identifiantStatique();
            break;
        default:
            break;
    }

    switch (intS)
    {
        case ID_TERMINAL:
            automate->decalage(new Etat31, s);
            return CONTINUE;

        case TERME:
        case EXPRESSION_MULT:
        case EXPRESSION_DIV:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat29);
            return CONTINUE;

        case FACTEUR:
        case CONSTANTE_NUMERIQUE:
        case IDENTIFICATEUR_FACTEUR:
        case EXPRESSION_PARENTHESEE:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat30);
            return CONTINUE;

        case PAROUV_TERMINAL:
            automate->decalage(new Etat33, s);
            return CONTINUE;

        case NUM_TERMINAL:
            automate->decalage(new Etat32, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
