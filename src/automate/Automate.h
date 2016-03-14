#ifndef LUTIN_AUTOMATE_H
#define LUTIN_AUTOMATE_H



#include <stack>
#include <Programme.h>
#include "EtatInterface.h"
#include "Symbole.h"
#include "Lexeur.h"

enum RETOUR_PAS{
    CONTINUE,
    TERMINE,
    ERREUR
};

class Automate
{
public:

    Automate(std::string nomFichier);

    void decalage(EtatInterface* nouvelEtat, Symbole* symboleActuel);

    void analyserProgramme();

    void optimiserProgramme();

    void afficherProgramme();

    void executerProgramme();

    Symbole *popSymbole();

    EtatInterface * popEtat();

    void pushEtat(EtatInterface *const etat);

    void pushSymbole(Symbole *const symbole);

    void popEtat(int nb);

    void setProgramme(Programme* programme);

    EtatInterface * etatCourant()const ;

    ~Automate();

private:
    std::stack<EtatInterface *> pilesEtats;

    std::stack<Symbole*> pilesSymboles;

    Lexeur *lexeur;

    Programme* programme;

    bool chargerProgramme();

    int pas();
};



#endif //LUTIN_AUTOMATE_H
