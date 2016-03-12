#include <BlocDeclaration.h>
#include <BlocInstruction.h>
#include <Programme.h>
#include "Etat0.h"
#include "EtatFin.h"
#include "Etat1.h"

bool Etat0::transition(Automate* automate, Symbole* s)
{
    switch (*s){
        case FIN_PROGRAMME: {
            BlocDeclaration *blocDeclaration = nullptr;
            BlocInstruction *blocInstruction = nullptr;
            Symbole *symb = automate->popSymbole();
            if (symb != nullptr && ((int) *symb == DECLARATION_CONSTANTE || (int) *symb == DECLARATION_VARIABLE)) {
                blocInstruction = (BlocInstruction *) symb;
                symb = automate->popSymbole();
            }
            if (symb != nullptr && ((int) *symb == INSTRUCTION_AFFECTATION || (int) *symb == INSTRUCTION_ECRITURE || (int) *symb == INSTRUCTION_LECTURE)) {
                blocDeclaration = (BlocDeclaration *) symb;
            }
            Programme *programme = new Programme(blocDeclaration, blocInstruction);
            automate->pushSymbole(programme);
            automate->pushEtat(new EtatFin);
            return automate->etatCourant()->transition(automate, s);
        }
        /*
        case PROGRAMME:
            automate->pushSymbole(s);
            automate->pushEtat(new EtatFin);
            return true;
        case BLOC_DECLARATION:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat1);
            return true;
        */
        case CONST_TERMINAL:
        case VAR_TERMINAL:
        case ID_TERMINAL:
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL: {
            // E1 fera la transition
            automate->pushEtat(new Etat1);
            return automate->etatCourant()->transition(automate, s);
        }
        default:
            return false;
    }
}
