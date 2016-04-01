#ifndef LUTIN_AUTOMATE_H
#define LUTIN_AUTOMATE_H


#include <stack>
#include <Programme.h>
#include "EtatInterface.h"
#include "Symbole.h"
#include "Lexeur.h"
#include "TableDesSymboles.h"

// Enumération pour la valeur de retour d'un pas dans l'automate.
enum RETOUR_PAS {
    CONTINUE,
    TERMINE,
    ERREUR
};
/*
 * Automate, classe principale de l'interpreteur lutin
 *
 */
class Automate {
public:
    // Constructeur prenant en paramètre le fichier à analyser
    Automate(std::string nomFichier);

    // Analyse statiquement le programme chargé en mémoire
    bool analyserProgramme();

    // Optimise le programme chargé en mémoire
    void optimiserProgramme();

    // Affiche le programme chargé en mémoire
    void afficherProgramme();

    // Execute le programme chargé en mémoire
    void executerProgramme();

    // Retourne True si un programme est correctement chargé, False sinon
    bool programmeEstCharge();

    // Empile un Etat et un Symbole, et décale la tête de lecture du lexeur
    void decalage(EtatInterface *nouvelEtat, Symbole *symboleActuel);

    // Retourne et pop le Symbole en haut de la pile de Symboles
    // doDelete permet de delete l'element et de retourner null
    // Retourne null si la pile est vide
    Symbole *popSymbole(bool doDelete);

    // Retourne et pop l'Etat en haut de la pile des Etats
    // Retourne null si la pile est vide
    EtatInterface *popEtat();

    // Push un nouvel Etat au sommet de la pile des Etats
    void pushEtat(EtatInterface *const etat);

    // Push un nouveau Symbole au sommet de la pile des Symboles
    void pushSymbole(Symbole *const symbole);

    // Pop un nombre défini nb d'Etat de la pile d'Etat
    void popEtat(int nb);

    // Retourne l'Etat courant de la pile des Etats, c'est a dire celui du haut de la pile
    EtatInterface *etatCourant() const;

    // Affecte un Programme chargé à l'automate
    void setProgramme(Programme *programme);

    // Affiche une erreur syntaxique
    void erreurSyntaxique(Symbole *s, std::string symboleManquant);

    ~Automate();

private:
    std::stack<EtatInterface *> pilesEtats;

    std::stack<Symbole *> pilesSymboles;

    Lexeur *lexeur;

    Programme *programme;

    bool chargerProgramme();

    bool programmeCharge;

    int pas();

};


#endif //LUTIN_AUTOMATE_H
