#include "Etat8.h"
#include "Etat19.h"

bool Etat8::transition(Automate* automate, Symbole* s)
{
   switch (*s){
        case POINT_VIRGULE_TERMINAL:
            automate->decalage(new Etat19, s);
            return CONTINUE;
		default:
           return false;
   }
}
