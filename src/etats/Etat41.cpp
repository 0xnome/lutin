#include "Etat41.h"
#include "ExpressionMult.h"

int Etat41::transition(Automate *automate, Symbole *s) {
    switch (*s) {
      // suivant Terme
      case MULT_TERMINAL:
      case DIV_TERMINAL:
      case PLUS_TERMINAL:
      case MOINS_TERMINAL:
      case PARFER_TERMINAL:
      case POINT_VIRGULE_TERMINAL:
      //recuperation des erreurs
      case LIRE_TERMINAL:
      case ECRIRE_TERMINAL:
      case ID_TERMINAL:
      case FIN_PROGRAMME:
      {
            Facteur* facteur = (Facteur*) automate->popSymbole();
            automate->popSymbole(); //mult
            Terme * terme = (Terme*) automate->popSymbole();
            automate->popEtat(3);

            ExpressionMult * expressionMult = new ExpressionMult(facteur, terme);
            return automate->etatCourant()->transition(automate, expressionMult);
        }
        default:
            return ERREUR;
    }
}
