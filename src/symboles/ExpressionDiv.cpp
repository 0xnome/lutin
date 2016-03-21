#include <easyloggingpp.h>
#include "ExpressionDiv.h"
#include "ConstanteNumerique.h"
#include "IdentificateurFacteur.h"

using namespace std;

ExpressionDiv::ExpressionDiv(Facteur *facteur, Terme *terme) : Terme(EXPRESSION_DIV), terme(terme), facteur(facteur)
{
}

ExpressionDiv::~ExpressionDiv()
{
    delete this->terme;
    delete this->facteur;
}

void ExpressionDiv::afficher()
{
    this->terme->afficher();
    cout << "/";
    this->facteur->afficher();
}

void ExpressionDiv::executer(TableDesSymboles *tableDesSymboles)
{

}

int ExpressionDiv::eval(TableDesSymboles *tablesDesSymboles)
{
    // TODO facteur doit etre différent de 0 !!!
    LOG(INFO) << "ExpressionDiv::eval";
    return terme->eval(tablesDesSymboles) / facteur->eval(tablesDesSymboles);
}

void ExpressionDiv::analyser(TableDesSymboles *tableDesSymboles)
{
    terme->analyser(tableDesSymboles);
    facteur->analyser(tableDesSymboles);

    if ((int) *facteur == CONSTANTE_NUMERIQUE)
    {
        ConstanteNumerique *constante = (ConstanteNumerique *) facteur;
        if (constante->eval(tableDesSymboles) == 0)
        {
            std::cerr << "Erreur ligne " << facteur->getLigne() << ":" << facteur->getColonne() <<
            " : Division par 0." << std::endl;
        }
    }

    if ((int) *facteur == IDENTIFICATEUR_FACTEUR)
    {
        IdentificateurFacteur *idfacteur = (IdentificateurFacteur *) facteur;
        if (tableDesSymboles->estConstante(idfacteur->getId()->getNom())
            && tableDesSymboles->getValeur(idfacteur->getId()->getNom()) == 0)
        {
            std::cerr << "Erreur ligne " << facteur->getLigne() << ":" << facteur->getColonne() <<
            " : Division par la constante '" <<
            idfacteur->getId()->getNom() << "' qui vaut 0." << std::endl;
        }
        else if (tableDesSymboles->getValeur(idfacteur->getId()->getNom()) == 0)
        {
            std::cerr << "Erreur ligne " << facteur->getLigne() << ":" << facteur->getColonne() <<
            " : Division par la variable '" <<
            idfacteur->getId()->getNom() << "' qui vaut 0." << std::endl;
        }
    }
}
