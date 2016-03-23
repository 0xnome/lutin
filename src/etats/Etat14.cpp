#include <IdTerminal.h>
#include <IdentificateurVariable.h>
#include "Etat14.h"

int Etat14::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        //suivant de IDS
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
            //On a lu un suivant de IDS
            IdTerminal *id = (IdTerminal *) automate->popSymbole(false);
            automate->popSymbole(true); // pop du VIRGULE_TERMINAL
            IdentificateurVariable *ids = (IdentificateurVariable *) automate->popSymbole(false); // IDS
            automate->popEtat(3);   // pop de 3 symboles, donc pop de 3 Etats, retour en E4

            // Etat courant : Etat4
            IdentificateurVariable *identificateurConstante = new IdentificateurVariable(id);

            // il faut insérer identificateurConstante à la fin de la file d'IdentificateurVariable.
            // on récupère la derniere IdentificateurVariable
            IdentificateurVariable *dernierIdentificateur = ids;
            while (dernierIdentificateur->getSuivant() != nullptr) {
                dernierIdentificateur = dernierIdentificateur->getSuivant();
            }
            // insertion dans la liste
            dernierIdentificateur->setSuivant(identificateurConstante);
            return automate->etatCourant()->transition(automate, ids);
        }
        default:
            return ERREUR;
    }
}
