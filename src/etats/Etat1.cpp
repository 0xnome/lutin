#include <InstructionAffectation.h>
#include "Etat1.h"
#include "Etat3.h"
#include "Etat2.h"
#include "Etat4.h"

int Etat1::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case CONST_TERMINAL:
            automate->decalage(new Etat3, s);
            return CONTINUE;
        case VAR_TERMINAL:
            automate->decalage(new Etat4, s);
            return CONTINUE;
        case FIN_PROGRAMME:
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL:
        case ID_TERMINAL: {
            // suivants de INSTRS
            // on fait une reduction qui produit un INSTRS vide (cas particulier)

            // ici on a mis une InstructionAffectation, mais ça n'a pas d'importance
            BlocInstruction *instrs = new InstructionAffectation();
            //faire la transition sur instrs
            return automate->etatCourant()->transition(automate, instrs);
        }
        case BLOC_INSTRUCTION:
        case INSTRUCTION_AFFECTATION:
        case INSTRUCTION_LECTURE:
        case INSTRUCTION_ECRITURE:
            // INSTRS
            automate->pushSymbole(s);
            automate->pushEtat(new Etat2);
            return CONTINUE;
        default:
            return ERREUR;
    }
}
