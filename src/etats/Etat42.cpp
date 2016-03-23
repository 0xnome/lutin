#include "Etat42.h"
#include "ExpressionDiv.h"

int Etat42::transition(Automate *automate, Symbole *s)
{
    switch (*s)
    {
        //suivant de Terme
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
            Facteur *facteur = (Facteur *) automate->popSymbole(false);
            automate->popSymbole(true); //div
            Terme *terme = (Terme *) automate->popSymbole(false);
            automate->popEtat(3);

            ExpressionDiv *expressionDiv = new ExpressionDiv(facteur, terme);
            return automate->etatCourant()->transition(automate, expressionDiv);
        }
        default:
            return ERREUR;
    }
}
