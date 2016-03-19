#include "Etat42.h"
#include "ExpressionDiv.h"

int Etat42::transition(Automate *automate, Symbole *s) {
    switch (*s) {
      case EXPRESSION_MULT:
      case EXPRESSION_DIV:
      case EXPRESSION_ADDITIVE:
      case EXPRESSION_SOUSTRACTIVE:
      case PARFER_TERMINAL:
      case POINT_VIRGULE_TERMINAL:
      {
          Facteur* facteur = (Facteur*) automate->popSymbole();
          automate->popSymbole(); //div
          Terme * terme = (Terme*) automate->popSymbole();
          automate->popEtat(3);

          ExpressionDiv * expressionDiv = new ExpressionDiv(facteur, terme);
          automate->etatCourant()->transition(automate, expressionDiv);

          return CONTINUE;
      }
      default:
          return ERREUR;
    }
}
