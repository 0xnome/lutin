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
           // on dépile le point virgule
           automate->popSymbole();  // pop du POINT_VIRGULE_TERMINAL
           AffectationConstante *affectationConstante = (AffectationConstante *) automate->popSymbole();
           automate->popSymbole(); // pop du CONST_TERMINAL

           DeclarationConstante *declarationConstante = new DeclarationConstante(affectationConstante);

           BlocDeclaration* blocDeclarationPrecedent = nullptr;
           Symbole* symb = automate->popSymbole();

           if(symb != nullptr && (int)*symb == BLOC_DECLARATION){
               blocDeclarationPrecedent = (BlocDeclaration*)symb;
           }

           if (blocDeclarationPrecedent != nullptr) {
               // le nouveau DeclarationConstante n'est pas le premier
               // On récupère le dernier blocDeclaration
               while((blocDeclarationPrecedent=blocDeclarationPrecedent->getSuivant())->getSuivant() != nullptr);
           }
           automate->popEtat(4);   // pop de 4 symboles, donc pop de 4 Etats

           // Etat courant : Etat0
           declarationConstante->setSuivant(blocDeclarationPrecedent);
           automate->pushSymbole(declarationConstante);

           return automate->etatCourant()->transition(automate, s);
       }
       default:
           return false;
   }
}
