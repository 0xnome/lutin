#include "Etat8.h"
#include "Etat19.h"

bool Etat8::transition(Automate* automate, Symbole* s)
{
   switch (*s){
        case POINT_VIRGULE_TERMINAL:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat19);
            return automate->decalage();
		default:
           return false;
   }
}
