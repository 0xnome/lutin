#include <InstructionAffectation.h>
#include "Etat1.h"
#include "Etat3.h"
#include "Etat2.h"

bool Etat1::transition(Automate* automate, Symbole* s)
{
    switch (*s){
        case CONST_TERMINAL:
            automate->decalage(new Etat3, s);
            return CONTINUE;
        case FIN_PROGRAMME:
        {
            // On lit un SUIVANT de INSTRS, donc on fait une reduction qui produit un INSTRS vide

            // ici on a mis une InstructionAffectation, mais ça n'a pas d'importance
            BlocInstruction* instrs = new InstructionAffectation(nullptr, nullptr);
            //faire la transition sur instrs
            return automate->etatCourant()->transition(automate,instrs);
        }
        case BLOC_INSTRUCTION:
        case INSTRUCTION_AFFECTATION:
        case INSTRUCTION_LECTURE:
        case INSTRUCTION_ECRITURE:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat2);
            return CONTINUE;
        default:
            return false;
    }
}
