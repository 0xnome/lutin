#include <IdTerminal.h>
#include <InstructionLecture.h>
#include "Etat22.h"

int Etat22::transition(Automate *automate, Symbole *s) {
    switch (*s) {
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL:
        case ID_TERMINAL:
        case FIN_PROGRAMME: {
            // on lit un suivant de INSTRS
            automate->popSymbole(true); // point virgule
            IdTerminal *id = (IdTerminal *) automate->popSymbole(false); // id
            automate->popSymbole(true); // lire
            BlocInstruction *instrs = (BlocInstruction *) automate->popSymbole(false); // INSTRS

            automate->popEtat(4); // on arrive en E1

            InstructionLecture *instructionLecture = new InstructionLecture(id);
            if (instrs->estVide()) {
                delete instrs;
                // alors la nouvelle InstructionLecture est le premier BlocInstruction
                return automate->etatCourant()->transition(automate, instructionLecture);
            }
            else {
                // il faut insérer instructionLecture à la fin de la file de BlocInstruction.
                // on récupère le dernier BlocInstruction
                BlocInstruction *dernierBloc = instrs;
                while (dernierBloc->getSuivant() != nullptr) {
                    dernierBloc = dernierBloc->getSuivant();
                }
                // insertion dans la liste
                dernierBloc->setSuivant(instructionLecture);
                return automate->etatCourant()->transition(automate, instrs);
            }
        }
        default:
            return ERREUR;
    }
}
