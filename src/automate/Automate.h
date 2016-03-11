#ifndef LUTIN_AUTOMATE_H
#define LUTIN_AUTOMATE_H



#include <stack>
#include "EtatInterface.h"
#include "Symbole.h"
#include "Lexeur.h"

class Automate
{
public:

    Automate(std::string nomFichier);

    void decalage();

    Symbole *popSymbole();

    EtatInterface * popEtat();

    void pushEtat(EtatInterface *const etat);

    void pushSymbole(Symbole *const symbole);

    void popEtat(int nb);


    EtatInterface * etatCourant()const ;

    ~Automate();

private:
    std::stack<EtatInterface *> pilesEtats;

    std::stack<Symbole*> pilesSymboles;

    Lexeur *lexeur;

};



#endif //LUTIN_AUTOMATE_H
