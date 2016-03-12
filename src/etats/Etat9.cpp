#include "Etat9.h"
#include "Etat21.h"

bool Etat9::transition(Automate* automate, Symbole* s)
{
   switch (*s){
       case EGAL_TERMINAL:
           automate->pushSymbole(s);
           automate->pushEtat(new Etat21;
           return automate->decalage();
		default:
           return false;
   }
}
