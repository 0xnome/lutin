#include <iostream>
#include "Etat.h"
#include "../automate/Automate.h"
#include "../symboles/Symbole.h"

EtatInterface::~EtatInterface(){}

// --------- Modèle --------- //
//bool EtatX::transition(Automate* automate, Symbole* s)
//{
//    switch (*s){
//        case xxx:
//			return true;
//		default:
//            return false;
//    }
//}
// ------------------------- //

Etat::~Etat(){}

bool Etat::transition(Automate *automate, Symbole *s)
{
    return false;
}

bool Etat0::transition(Automate* automate, Symbole* s)
{
    switch (*s){
        case PROGRAMME:
			automate->pushSymbole(s);
            automate->pushEtat(new EtatFin());
            return true;
        case BLOCS_DECLARATION:
			automate->pushSymbole(s);
            automate->pushEtat(new Etat1());
            return true;
        default:
            return false;
    }
}

bool Etat1::transition(Automate* automate, Symbole* s)
{
	switch (*s){
        case CONST_TERMINAL:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat3());
            automate->decalage();
			return true;
        case VAR_TERMINAL:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat4());
            automate->decalage();
            return true;
        case BLOC_INSTRUCTIONS:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat2());
            return true;
        default:
            return false;
    }
}

bool Etat3::transition(Automate* automate, Symbole* s)
{
    switch (*s){
        case AFFECTATION_CONSTANTE:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat8());
            return true;
        case VAR_TERMINAL:
            automate->pushSymbole(s);
            automate->pushEtat(new Etat9());
            automate->decalage();
            return true;
        default:
            return false;
    }
}

