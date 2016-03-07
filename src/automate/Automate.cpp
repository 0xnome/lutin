#include <Etat.h>
#include <Automate.h>

void Automate::decalage(Etat * etat)
{
    Etat * e = new Etat0();
    std::cout << e << std::endl;
}

Etat* Automate::popEtat()
{
    Etat* etat = pilesEtats.top();
    pilesEtats.pop();
    return etat;
}

Symbole* Automate::popSymbole()
{
    Symbole * symbole = pilesSymboles.top();
    pilesSymboles.pop();
    return symbole;
}

void Automate::pushEtat(Etat * const etat)
{
    pilesEtats.push(etat);
}

void Automate::pushSymbole(Symbole * const symbole)
{
    pilesSymboles.push(symbole);
}

void Automate::popEtat(int nb)
{
    for (int i = 0; i < nb; ++i)
    {
        pilesEtats.pop();
    }
}










