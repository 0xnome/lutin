#include <Etat.h>
#include "Automate.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void Automate::decalage()
{
    // TODO : récuperer le symbole
    lexeur->getNext();
//    this->etatCourant()->transition(this, nullptr);

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

Automate::Automate(string nomFichier)
{

    ifstream fluxFichier(nomFichier);
    if(fluxFichier)
    {
        string contenuDuFichier((istreambuf_iterator<char>(fluxFichier)), istreambuf_iterator<char>());

        // split du fichier ligne par ligne
        stringstream stringstream(contenuDuFichier);
        char delimiteur = '\n';
        string ligne;
        vector<string> lignesDuFichier;
        while (getline(stringstream,ligne,delimiteur))
        {
            lignesDuFichier.push_back(ligne);
        }

        lexeur = new Lexeur(lignesDuFichier);

// Pour tester le lexeur
        cout << "lexeur ..." << endl;
        Symbole* symb;
        while((symb = lexeur->getNext()) != nullptr){
            cout << *symb << endl;
        }
        cout << "fin lexeur ..." << endl;


    }
    else
    {
        std::cerr << "Erreur a l'ouverture du fichier " << nomFichier << std::endl;
        exit(1);
    }

}

Automate::~Automate()
{
    delete lexeur;
}

Etat *Automate::etatCourant() const
{
    return pilesEtats.top();
}


