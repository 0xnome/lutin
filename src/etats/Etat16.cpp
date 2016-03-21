#include "Etat16.h"
#include "Etat44.h"
#include "Etat23.h"
#include "Etat24.h"

int Etat16::transition(Automate *automate, Symbole *s)
{
    switch (*s)
    {
        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat44, s);
            return CONTINUE;
        case PLUS_TERMINAL:
            automate->decalage(new Etat23, s);
            return CONTINUE;
        case MOINS_TERMINAL:
            automate->decalage(new Etat24, s);
            return CONTINUE;
        //recuperation des erreurs
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL:
        case ID_TERMINAL:
        case FIN_PROGRAMME:
        {
            Symbole* symboleOublie = new Symbole(POINT_VIRGULE_TERMINAL);
            automate->pushSymbole(symboleOublie);
            automate->pushEtat(new Etat44);
            return CONTINUE;
        }
        default:
            return ERREUR;
    }
}
