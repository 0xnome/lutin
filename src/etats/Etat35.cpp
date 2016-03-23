#include <IdTerminal.h>
#include <Expression.h>
#include <InstructionAffectation.h>
#include "Etat35.h"

int Etat35::transition(Automate *automate, Symbole *s)
{
    switch (*s)
    {
        case LIRE_TERMINAL:
        case ECRIRE_TERMINAL:
        case ID_TERMINAL:
        case FIN_PROGRAMME:
        {
            // on lit un suivant de INSTRS
            automate->popSymbole(true); // point virgule
            Expression *exp = (Expression *) automate->popSymbole(false); // Exp
            automate->popSymbole(true); // opaff
            IdTerminal *id = (IdTerminal *) automate->popSymbole(false);// id
            BlocInstruction *instrs = (BlocInstruction *) automate->popSymbole(false); // INSTRS

            automate->popEtat(5);

            InstructionAffectation *instructionAffectation = new InstructionAffectation(exp, id);
            if (instrs->estVide())
            {
                delete instrs;
                // alors la nouvelle InstructionLecture est le premier BlocInstruction
                return automate->etatCourant()->transition(automate, instructionAffectation);
            }
            else
            {
                // il faut insérer instructionLecture à la fin de la file de BlocInstruction.
                // on récupère le dernier BlocInstruction
                BlocInstruction *dernierBloc = instrs;
                while (dernierBloc->getSuivant() != nullptr)
                {
                    dernierBloc = dernierBloc->getSuivant();
                }
                // insertion dans la liste
                dernierBloc->setSuivant(instructionAffectation);
                return automate->etatCourant()->transition(automate, instrs);
            }
        }
        default:
            return ERREUR;
    }
}
