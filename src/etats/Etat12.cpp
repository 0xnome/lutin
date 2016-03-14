#include <IdentificateurVariable.h>
#include <DeclarationVariable.h>
#include "Etat12.h"

int Etat12::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL:
        case ID_TERMINAL:
        case VAR_TERMINAL:
        case CONST_TERMINAL:
        case FIN_PROGRAMME: {
            // on lit un suivant de DECS
            automate->popSymbole(); // point virgule
            IdentificateurVariable *ids = (IdentificateurVariable *) automate->popSymbole(); // IDS
            automate->popSymbole(); // var
            BlocDeclaration *decs = (BlocDeclaration *) automate->popSymbole(); // DECS

            automate->popEtat(4); // on arrive en E0

            DeclarationVariable *declarationVariable = new DeclarationVariable(ids);
            if (decs->estVide()) {
                // alors la nouvelle DeclarationVariable est est le premier BlocDeclaration
                return automate->etatCourant()->transition(automate, declarationVariable);
            }
            else {
                // il faut insérer declarationVariable à la fin de la file de BlocDeclaration.
                // on récupère le dernier BlocDeclaration
                BlocDeclaration *dernierBloc = decs;
                while (dernierBloc->getSuivant() != nullptr) {
                    dernierBloc = dernierBloc->getSuivant();
                }
                // insertion dans la liste
                dernierBloc->setSuivant(declarationVariable);
                return automate->etatCourant()->transition(automate, decs);
            }
        }
        default:
            return ERREUR;
    }
}
