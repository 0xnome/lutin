#include <BlocDeclaration.h>
#include <BlocInstruction.h>
#include <Programme.h>
#include <DeclarationConstante.h>
#include "Etat0.h"
#include "EtatFin.h"
#include "Etat1.h"

int Etat0::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case PROGRAMME:
            // PROG
            automate->pushSymbole(s);
            automate->pushEtat(new EtatFin);
            return CONTINUE;
        case BLOC_DECLARATION:
        case DECLARATION_CONSTANTE:
        case DECLARATION_VARIABLE:
            // DECS
            automate->pushSymbole(s);
            automate->pushEtat(new Etat1);
            return CONTINUE;
        case CONST_TERMINAL:
        case VAR_TERMINAL:
        case ID_TERMINAL:
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL:
        case FIN_PROGRAMME: {
            // suivants de DECS
            // on fait une reduction qui produit un DECS vide (cas particulier ici)

            // on a mis une DeclarationConstante, mais ça n'a pas d'importance
            BlocDeclaration *decs = new DeclarationConstante(nullptr);
            //faire la transition sur decs
            return automate->etatCourant()->transition(automate, decs);
        }
        default:
            return ERREUR;
    }
}
