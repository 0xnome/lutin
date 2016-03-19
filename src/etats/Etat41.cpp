#include "Etat41.h"
#include "ExpressionMult.h"

int Etat41::transition(Automate *automate, Symbole *s) {
    switch (*s) {
      case EXPRESSION_MULT:
      case EXPRESSION_DIV:
      case EXPRESSION_ADDITIVE:
      case EXPRESSION_SOUSTRACTIVE:
      case PARFER_TERMINAL:
      case POINT_VIRGULE_TERMINAL:
      {
            Facteur* facteur = (Facteur*) automate->popSymbole();
            automate->popSymbole(); //mult
            Terme * terme = (Terme*) automate->popSymbole();
            automate->popEtat(3);

            ExpressionMult * expressionMult = new ExpressionMult(facteur, terme);
            automate->etatCourant()->transition(automate, expressionMult);

            return CONTINUE;
        }
        default:
            return ERREUR;
    }
}
