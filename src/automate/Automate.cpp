#include "EtatDefaut.h"
#include "Automate.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <Etat0.h>

using namespace std;

void Automate::decalage(EtatInterface* nouvelEtat, Symbole* symboleActuel)
{
    //empiler etat et symbole
    this->pushEtat(nouvelEtat);
    this->pushSymbole(symboleActuel);

    // on decale la tete de lecture
    lexeur->shift();
}

EtatInterface * Automate::popEtat()
{
    EtatInterface * etat = pilesEtats.top();
    pilesEtats.pop();
    cout << "(POP1) nouvel Etat courant : " << etat->getNom() << endl;
    return etat;
}

Symbole* Automate::popSymbole()
{
    if(pilesSymboles.empty()){
        return nullptr;
    }
    Symbole * symbole = pilesSymboles.top();
    cout << "(POP) Symbole pop : " << Symbole::getName(symbole) << endl;
    pilesSymboles.pop();
    return symbole;
}

void Automate::pushEtat(EtatInterface *const etat)
{
    cout << "(PUSH) nouvel etat courant : " << etat->getNom() << endl;
    pilesEtats.push(etat);
}

void Automate::pushSymbole(Symbole * const symbole)
{
    cout << "(PUSH) nouveau symbole reconnu : " << Symbole::getName(symbole) << endl;
    pilesSymboles.push(symbole);
}

void Automate::popEtat(int nb)
{
    for (int i = 0; i < nb; ++i)
    {
        EtatInterface* e = pilesEtats.top();
        pilesEtats.pop();
        delete e;
    }
    cout << "(POP" << nb << ") nouvel etat courant : " << this->etatCourant()->getNom() << endl;
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
        this->programme = nullptr;
        cout << "chargement : " << this->chargerProgramme() << endl;
        cout << "programme charge." << endl;
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

EtatInterface * Automate::etatCourant() const
{
    return pilesEtats.top();
}


void Automate::setProgramme(Programme *nouveauProgramme) {
    if(this->programme != nullptr)
    {
        delete this->programme;
    }
    this->programme = nouveauProgramme;
}

bool Automate::chargerProgramme() {
    // tant que l'automate n'est pas terminé
    int pasRetour;

    // boucle principale
    do{
        pasRetour = this->pas();
    }while(pasRetour == CONTINUE);

    if(pasRetour == ERREUR){
        return false;
    }
    else if(pasRetour == TERMINE){
        return true;
    }
    return false;
}

void Automate::afficherProgramme() {
    cout << "AFFICHAGE DU PROGRAMME" << endl;
    this->programme->afficher();
}

int Automate::pas() {
    Symbole *s = this->lexeur->getCourant();
    return this->etatCourant()->transition(this, s);
}
