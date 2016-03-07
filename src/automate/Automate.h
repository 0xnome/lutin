#ifndef LUTIN_AUTOMATE_H
#define LUTIN_AUTOMATE_H


#include <stack>
#include <Etat.h>
#include <Symbole.h>
#include <Lexeur.h>

class Etat;

class Automate
{
public:

    Automate(std::string nomFichier);

    void decalage();

    Symbole *popSymbole();

    Etat *popEtat();

    void pushEtat(Etat *const etat);

    void pushSymbole(Symbole *const symbole);

    void popEtat(int nb);


    Etat* etatCourant()const ;

    ~Automate();

private:
    std::stack<Etat*> pilesEtats;

    std::stack<Symbole*> pilesSymboles;

    Lexeur *lexeur;

};



#endif //LUTIN_AUTOMATE_H
