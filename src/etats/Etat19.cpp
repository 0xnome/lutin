#include "IdTerminal.h"
#include "AffectationConstante.h"
#include "DeclarationConstante.h"
#include "Etat19.h"

bool Etat19::transition(Automate* automate, Symbole* s)
{
   switch (*s){
       /*
       case LIRE_TERMINAL:
       case ECRIRE_TERMINAL:
       case ID_TERMINAL:
       case VAR_TERMINAL:
       case CONST_TERMINAL:
        */
       case FIN_PROGRAMME: {
           // on lit un suivant de DECS
           automate->popSymbole(); // point virgule
           AffectationConstante* affects = (AffectationConstante*) automate->popSymbole(); // AFFECTS
           automate->popSymbole(); // const
           BlocDeclaration* decs = (BlocDeclaration*) automate->popSymbole(); // DECS

           automate->popEtat(4); // on arrive en E0

           DeclarationConstante* declarationConstante = new DeclarationConstante(affects);
           if(decs->estVide()){
               // alors la nouvelle DelcarationContanteest est le premier BlocDeclaration
               return automate->etatCourant()->transition(automate, declarationConstante);
           }
           else{
               // il faut insérer declarationConstante à la fin de la file de BlocDeclaration.
               // on récupère le dernier BlocDeclaration
               BlocDeclaration* dernierBloc = decs;
               while(dernierBloc->getSuivant() != nullptr){
                   dernierBloc = dernierBloc->getSuivant();
               }
               // insertion dans la liste
               dernierBloc->setSuivant(declarationConstante);
               return automate->etatCourant()->transition(automate, decs);
           }
       }
       default:
           return false;
   }
}
