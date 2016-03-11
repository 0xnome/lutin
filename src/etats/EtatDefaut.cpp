#include <iostream>
#include "EtatDefaut.h"
#include "SymbolesTerminaux.h"
#include "SymbolesNonTerminaux.h"


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


bool EtatDefaut::transition(Automate *automate, Symbole *s)
{
    return false;
}

/*
bool Etat0::transition(Automate* automate, Symbole* s)
{
    switch (*s){
    case PROGRAMME:
        automate->pushSymbole(s);
        automate->pushEtat(new EtatFin());
        return true;
    case BLOC_DECLARATION:
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
    case BLOC_INSTRUCTION:
        automate->pushSymbole(s);
        automate->pushEtat(new Etat2());
        return true;
    default:
        return false;
    }
}

// TODO
bool Etat2::transition(Automate* automate, Symbole* s)
{
    return false;
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

bool Etat28::transition(Automate* automate, Symbole* s)
{
    NumTerminal* num;
    IdTerminal* id;
    AffectationConstante* affects;
    switch (*s){
    case VIRGULE_TERMINAL:
    case POINT_VIRGULE_TERMINAL:
        num = (NumTerminal*) automate->popSymbole();
        automate->popSymbole();
        id = (IdTerminal*) automate->popSymbole();
        automate->popEtat(3);
        affects = new AffectationConstante(id, num);
        automate->etatCourant()->transition(automate, affects);
                // associer un identifiant de symbole à la classe, p-e en paramètre de la classe pour pouvoir modifier selon d'ou on vient
        return true;
    default:
        return false;
    }
}
*/