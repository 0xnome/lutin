#include "EtatDefaut.h"
#include "Automate.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <Etat0.h>
#include "easyloggingpp.h"

using namespace std;

bool Automate::decalage()
{
    Symbole *symbole = lexeur->getNext();
    LOG(INFO) << "lecture de " << Symbole::getName(symbole) << endl;
    if ((int) *symbole == ERREUR_LEXICALE)
    {
        //TODO gestion si lecture d'erreur
    }
    return this->etatCourant()->transition(this, symbole);
}

EtatInterface *Automate::popEtat()
{
    EtatInterface *etat = pilesEtats.top();
    pilesEtats.pop();
    LOG(INFO) << "(POP1) nouvel Etat courant : " << etat->getNom() << endl;
    return etat;
}

Symbole *Automate::popSymbole()
{
    if (pilesSymboles.empty())
    {
        return nullptr;
    }
    Symbole *symbole = pilesSymboles.top();
    LOG(INFO) << "(POP) Symbole pop : " << Symbole::getName(symbole) << endl;
    pilesSymboles.pop();
    return symbole;
}

void Automate::pushEtat(EtatInterface *const etat)
{
    LOG(INFO) << "(PUSH) nouvel etat courant : " << etat->getNom() << endl;
    pilesEtats.push(etat);
}

void Automate::pushSymbole(Symbole *const symbole)
{
    LOG(INFO) << "(PUSH) nouveau symbole reconnu : " << Symbole::getName(symbole) << endl;
    pilesSymboles.push(symbole);
}

void Automate::popEtat(int nb)
{
    for (int i = 0; i < nb; ++i)
    {
        EtatInterface *e = pilesEtats.top();
        pilesEtats.pop();
        delete e;
    }
    LOG(INFO) << "(POP" << nb << ") nouvel etat courant : " << this->etatCourant()->getNom() << endl;
}

Automate::Automate(string nomFichier)
{
    ifstream fluxFichier(nomFichier);
    if (fluxFichier)
    {
        string contenuDuFichier((istreambuf_iterator<char>(fluxFichier)), istreambuf_iterator<char>());

        // split du fichier ligne par ligne
        stringstream stringstream(contenuDuFichier);
        char delimiteur = '\n';
        string ligne;
        vector<string> lignesDuFichier;
        while (getline(stringstream, ligne, delimiteur))
        {
            lignesDuFichier.push_back(ligne);
        }

        lexeur = new Lexeur(lignesDuFichier);
        this->programme = nullptr;
        LOG(INFO) << "chargement : " << this->chargerProgramme() << endl;
        LOG(INFO) << "programme charge." << endl;
/*
// Pour tester le lexeur
        cout << "lexeur ..." << endl;
        Symbole* symb;
        while((symb = lexeur->getNext()) != nullptr){
            cout << *symb << endl;
        }
        cout << "fin lexeur ..." << endl;
*/
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
    delete programme;
}

EtatInterface *Automate::etatCourant() const
{
    return pilesEtats.top();
}


void Automate::setProgramme(Programme *nouveauProgramme)
{
    if (this->programme != nullptr)
    {
        delete this->programme;
    }
    this->programme = nouveauProgramme;
}

bool Automate::chargerProgramme()
{
    this->pushEtat(new Etat0());
    return this->decalage();
}

void Automate::afficherProgramme()
{
    LOG(INFO)  << "AFFICHAGE DU PROGRAMME" << endl;
    this->programme->afficher();
}

void Automate::analyserProgramme()
{
    LOG(INFO) << "ANALYSE DU PROGRAMME" << endl;
    this->programme->analyser();
}

void Automate::optimiserProgramme()
{
    LOG(INFO) << "OPTIMISATION DU PROGRAMME" << endl;
    this->programme->optimiser();
}

void Automate::executerProgramme()
{
    LOG(DEBUG) << "EXECUTION DU PROGRAMME" << endl;
    //this->programme->executer();
}
