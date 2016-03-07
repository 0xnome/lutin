#ifndef LUTIN_AUTOMATE_H
#define LUTIN_AUTOMATE_H


#include <stack>
#include <Etat.h>
#include <Symbole.h>

class Etat;

class Automate
{
public:



    void decalage(Etat *etat);

    Symbole *popSymbole();

    Etat *popEtat();

    void pushEtat(Etat *const etat);

    void pushSymbole(Symbole *const symbole);

    void popEtat(int nb);

private:
    std::stack<Etat *> pilesEtats;

    std::stack<Symbole *> pilesSymboles;


};


#endif //LUTIN_AUTOMATE_H
