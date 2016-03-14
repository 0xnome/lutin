#include "Etat2.h"

bool Etat2::transition(Automate* automate, Symbole* s)
{
   switch (*s){
       case FIN_PROGRAMME: {
           // on lit un suivant de prog
           BlocInstruction *instrs = (BlocInstruction *) automate->popSymbole(); // INSTRS
           BlocDeclaration *decs = (BlocDeclaration *) automate->popSymbole(); // DECS
           // on arrive à l'etat0
           automate->popEtat(2);
           Programme *prog = new Programme(decs, instrs);
           return automate->etatCourant()->transition(automate, prog);
       }
       default:
           return false;
   }
}
