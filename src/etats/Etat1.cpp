#include "Etat1.h"
#include "Etat3.h"
#include "Etat4.h"
#include "Etat2.h"

bool Etat1::transition(Automate* automate, Symbole* s)
{
    switch (*s){
        case CONST_TERMINAL:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat3);
            return automate->decalage();
            /*
        case VAR_TERMINAL:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat4);
            automate->decalage();
            return true;
        */
        /*
        case BLOC_INSTRUCTION:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat2);
            return true;
         */
        default:
            return false;
    }
}
