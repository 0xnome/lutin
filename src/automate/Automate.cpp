#include "EtatDefaut.h"
#include <fstream>
#include <sstream>
#include <Etat0.h>
#include "easyloggingpp.h"

using namespace std;

void Automate::decalage(EtatInterface *nouvelEtat, Symbole *symboleActuel)
{
    //empiler etat et symbole
    this->pushSymbole(symboleActuel);
    this->pushEtat(nouvelEtat);

    // on decale la tete de lecture
    lexeur->shift();
}

EtatInterface *Automate::popEtat()
{
    EtatInterface *etat = pilesEtats.top();
    pilesEtats.pop();
    LOG(INFO) << "(POP1) nouvel Etat courant : " << etat->getNom();
    return etat;
}

Symbole *Automate::popSymbole()
{
    if (pilesSymboles.empty())
    {
        return nullptr;
    }
    Symbole *symbole = pilesSymboles.top();
    LOG(INFO) << "(POP) Symbole pop : " << Symbole::getName(symbole);
    pilesSymboles.pop();
    return symbole;
}

void Automate::pushEtat(EtatInterface *const etat)
{
    LOG(INFO) << "(PUSH) nouvel etat courant : " << etat->getNom();
    pilesEtats.push(etat);
}

void Automate::pushSymbole(Symbole *const symbole)
{
    LOG(INFO) << "(PUSH) nouveau symbole reconnu : " << Symbole::getName(symbole);
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
    LOG(INFO) << "(POP" << nb << ") nouvel etat courant : " << this->etatCourant()->getNom();
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
        getline(stringstream, ligne, delimiteur);
        do
        {
            lignesDuFichier.push_back(ligne);
        }
        while (getline(stringstream, ligne, delimiteur));

        lexeur = new Lexeur(lignesDuFichier);
        this->programme = nullptr;

        if (this->chargerProgramme())
        {
            LOG(INFO) << "chargement : REUSSI";
            this->programmeCharge = true;
        }
        else
        {
            LOG(ERROR) << "chargement : ECHOUE";
            this->programmeCharge = false;
        }
/*
// Pour tester le lexeur
        cout << "lexeur ..." ;
        Symbole* symb;
        while((symb = lexeur->getCurrent()) != nullptr){
            cout << *symb ;
            this->lexeur->shift();
        }
        cout << "fin lexeur ..." ;
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
    int pasRetour;
    //initialisation de la pile à l'Etat0
    this->pushEtat(new Etat0);
    // boucle principale
    do
    {
        pasRetour = this->pas();
    } while (pasRetour == CONTINUE);

    if (pasRetour == ERREUR)
    {
        LOG(ERROR) << "Erreur d'execution du programme lors de la transition dans l'etat "
        << this->etatCourant()->getNom() << " sur le symbole "
        << Symbole::getName(this->lexeur->getCurrent());
        return false;
    }
    else if (pasRetour == TERMINE)
    {
        return true;
    }
    return false;
}

int Automate::pas()
{
    Symbole *s = this->lexeur->getCurrent();
    while ((int) *s == ERREUR_LEXICALE)
    {
        this->lexeur->shift();
        s = this->lexeur->getCurrent();
    }
    s = this->lexeur->getCurrent();
    return this->etatCourant()->transition(this, s);
}

void Automate::afficherProgramme()
{
    LOG(INFO) << "AFFICHAGE DU PROGRAMME";
    this->programme->afficher();
}

bool Automate::analyserProgramme()
{
    LOG(INFO) << "ANALYSE DU PROGRAMME";
    TableDesSymboles table;
    bool ret = this->programme->analyser(&table);
    std::unordered_map<std::string, Entree *> mapVariables = table.getListVariablesNonUtilisees();
    std::unordered_map<std::string, Entree *> mapConstantes = table.getListConstatnesNonUtilisees();

    for (auto it = mapVariables.begin(); it != mapVariables.end(); it++)
    {
        cerr << "Warining ligne " << it->second->ligne << ":" << it->second->colonne << " : La variable '" << it->first
        << "' n'est pas utilisée." << endl;
    }

    for (auto it = mapConstantes.begin(); it != mapConstantes.end(); it++)
    {
        cerr << "Warining ligne " << it->second->ligne << ":" << it->second->colonne << " : La constante '" << it->first
        << "' n'est pas utilisée." << endl;
    }
    return ret;
}

void Automate::optimiserProgramme()
{
    LOG(INFO) << "OPTIMISATION DU PROGRAMME";
    TableDesSymboles table;
    this->programme->optimiser(&table);
}

void Automate::executerProgramme()
{
    LOG(DEBUG) << "EXECUTION DU PROGRAMME";
    TableDesSymboles table;
    this->programme->executer(&table);
}

bool Automate::programmeEstCharge()
{
    return this->programmeCharge;
}
