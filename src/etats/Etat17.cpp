#include <Terme.h>
#include "Etat17.h"
#include "Etat37.h"
#include "Etat38.h"

int Etat17::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        // suivant de Expression
        case PARFER_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
        case PLUS_TERMINAL:
        case MOINS_TERMINAL:
            //recuperation des erreurs
        case FIN_PROGRAMME:
        case ECRIRE_TERMINAL:
        case LIRE_TERMINAL:
        case ID_TERMINAL: {
            Terme *terme = (Terme *) automate->popSymbole(false);
            automate->popEtat(1);
            // attention cast et passage en statique
            terme->setStatiqueClasse(EXPRESSION);
            Expression *expression = (Expression *) terme;
            return automate->etatCourant()->transition(automate, expression);
        }
        case MULT_TERMINAL:
            automate->decalage(new Etat37, s);
            return CONTINUE;
        case DIV_TERMINAL:
            automate->decalage(new Etat38, s);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
