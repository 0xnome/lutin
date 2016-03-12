#include "Etat21.h"
#include "Etat28.h"

bool Etat21::transition(Automate* automate, Symbole* s)
{
   switch (*s){
       case NUM_TERMINAL:
           automate->pushSymbole(s);
           automate->pushEtat(new Etat28);
           return automate->decalage();
		default:
           return false;
   }
}
