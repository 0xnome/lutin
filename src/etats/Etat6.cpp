#include <Expression.h>
#include "Etat6.h"
#include "Etat31.h"
#include "Etat32.h"
#include "Etat33.h"
#include "Etat30.h"
#include "Etat17.h"
#include "Etat16.h"


int Etat6::transition(Automate *automate, Symbole *s) {
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

    switch (intS) {
        case NUM_TERMINAL:
            automate->decalage(new Etat32, s);
            return CONTINUE;

        case PAROUV_TERMINAL:
            automate->decalage(new Etat33, s);
            return CONTINUE;

        case ID_TERMINAL:
            automate->decalage(new Etat31, s);
            return CONTINUE;

        case FACTEUR:
        case CONSTANTE_NUMERIQUE:
        case IDENTIFICATEUR_FACTEUR:
        case EXPRESSION_PARENTHESEE:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat30);
            return CONTINUE;

        case TERME:
        case EXPRESSION_MULT:
        case EXPRESSION_DIV:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat17);
            return CONTINUE;

        case EXPRESSION:
        case EXPRESSION_ADDITIVE:
        case EXPRESSION_SOUSTRACTIVE:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat16);
            return CONTINUE;

        default:
            return ERREUR;
    }
}
