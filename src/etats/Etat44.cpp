#include "Etat44.h"
#include "InstructionEcriture.h"
#include "Expression.h"
#include "BlocInstruction.h"

int Etat44::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case FIN_PROGRAMME:
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL:
        case ID_TERMINAL:
        {
            automate->popSymbole(); // point virgule
            Expression* expression = (Expression *) automate->popSymbole(); // expr
            automate->popSymbole(); //ecrire
            BlocInstruction *instrs = (BlocInstruction *) automate->popSymbole(); // INSTRS

            automate->popEtat(4);

            InstructionEcriture * instrEcriture = new InstructionEcriture(expression);

            if (instrs->estVide()) {
                // alors la nouvelle InstructionLecture est le premier BlocInstruction
                return automate->etatCourant()->transition(automate, instrEcriture);
            }
            else {
                // il faut insérer instrEcriture à la fin de la file de BlocInstruction.
                // on récupère le dernier BlocInstruction
                BlocInstruction *dernierBloc = instrs;
                while (dernierBloc->getSuivant() != nullptr) {
                    dernierBloc = dernierBloc->getSuivant();
                }
                // insertion dans la liste
                dernierBloc->setSuivant(instrEcriture);
                return automate->etatCourant()->transition(automate, instrs);
            }
        }
        default:
            return ERREUR;
    }
}
