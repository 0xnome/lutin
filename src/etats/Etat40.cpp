#include <NumTerminal.h>
#include <IdTerminal.h>
#include <AffectationConstante.h>
#include "Etat40.h"

int Etat40::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        // suivant de AFFECTS
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
            automate->popSymbole(); // pop du VIRGULE_TERMINAL
            AffectationConstante *affects = (AffectationConstante *) automate->popSymbole();
            automate->popEtat(5);   // pop de 5 symboles, donc pop de 5 Etats, retour en E3

            // Etat courant : Etat3
            AffectationConstante *affectationConstante = new AffectationConstante(id, num);

            // il faut insérer affectationConstante à la fin de la file d'AffectationConstante.
            // on récupère la derniere AffectationConstante
            AffectationConstante *dernierAffectation = affects;
            while (dernierAffectation->getSuivant() != nullptr) {
                dernierAffectation = dernierAffectation->getSuivant();
            }
            // insertion dans la liste
            dernierAffectation->setSuivant(affectationConstante);
            return automate->etatCourant()->transition(automate, affects);
        }

        default:
            return ERREUR;
    }
}
