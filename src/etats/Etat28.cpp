#include <NumTerminal.h>
#include <IdTerminal.h>
#include <AffectationConstante.h>
#include "Etat28.h"

int Etat28::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        //suivant de Affects
        case VIRGULE_TERMINAL:
        case POINT_VIRGULE_TERMINAL:
        //recuperation des erreurs
        case VAR_TERMINAL:
        case CONST_TERMINAL:
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL :
        case ID_TERMINAL:
        case FIN_PROGRAMME:
         {
            //On a lu un suivant de AFFECTS
            NumTerminal *num = (NumTerminal *) automate->popSymbole();
            automate->popSymbole(); // pop du EGAL_TERMINAL
            IdTerminal *id = (IdTerminal *) automate->popSymbole();
            automate->popEtat(3);   // pop de 3 symboles, donc pop de 3 Etats

            // Etat courant : Etat3
            AffectationConstante *affects = new AffectationConstante(id, num);

            return automate->etatCourant()->transition(automate, affects);
        }
        default:
            return ERREUR;
    }
}
