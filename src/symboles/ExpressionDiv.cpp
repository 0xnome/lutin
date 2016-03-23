#include <easyloggingpp.h>
#include "ExpressionDiv.h"
#include "ConstanteNumerique.h"
#include "IdentificateurFacteur.h"

using namespace std;

ExpressionDiv::ExpressionDiv(Facteur *facteur, Terme *terme) : Terme(EXPRESSION_DIV, terme->getLigne(), terme->getColonne()), terme(terme), facteur(facteur)
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
    LOG(INFO) << "ExpressionDiv::eval";
    if (analyser(tablesDesSymboles))
    {

        if (facteur->eval(tablesDesSymboles) == 0)
        {
            std::cerr << "Erreur lors de l'execution, ligne " << facteur->getLigne() << ":" << facteur->getColonne() <<
            " : Division par 0." << std::endl;
            exit(1);
        }
        return terme->eval(tablesDesSymboles) / facteur->eval(tablesDesSymboles);
    } else
    {
        exit(1);
    }
}

bool ExpressionDiv::estConstante(TableDesSymboles *tableDesSymboles)
{
    return this->facteur->estConstante(tableDesSymboles) && this->terme->estConstante(tableDesSymboles);
}

void ExpressionDiv::optimiser(TableDesSymboles *tableDesSymboles)
{
    this->facteur->optimiser(tableDesSymboles);
    if (this->facteur->estConstante(tableDesSymboles))
    {
        int val = this->facteur->eval(tableDesSymboles);
        Facteur *fact = new ConstanteNumerique(
                new NumTerminal(val, this->facteur->getLigne(), this->facteur->getColonne()));
        delete this->facteur;
        this->facteur = fact;
    }
    this->terme->optimiser(tableDesSymboles);
    if (this->terme->estConstante(tableDesSymboles))
    {
        int val = this->terme->eval(tableDesSymboles);
        Terme *ter = new ConstanteNumerique(new NumTerminal(val, this->terme->getLigne(), this->terme->getColonne()));
        delete this->terme;
        this->terme = ter;
    }
}

bool ExpressionDiv::analyser(TableDesSymboles *tableDesSymboles)
{
    bool ret = true;
    ret = ret & terme->analyser(tableDesSymboles);
    ret = ret & facteur->analyser(tableDesSymboles);

    if (ret)
    {
        if ((int) *facteur == CONSTANTE_NUMERIQUE)
        {
            ConstanteNumerique *constante = (ConstanteNumerique *) facteur;
            if (constante->eval(tableDesSymboles) == 0)
            {
                std::cerr << "Erreur ligne " << facteur->getLigne() << ":" << facteur->getColonne() <<
                " : Division par 0." << std::endl;
            }
            ret = false;
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
                ret = false;
            }
            else if (tableDesSymboles->getValeur(idfacteur->getId()->getNom()) != nullptr)
            {
                if (*(tableDesSymboles->getValeur(idfacteur->getId()->getNom())) == 0)
                {
                    std::cerr << "Erreur ligne " << facteur->getLigne() << ":" << facteur->getColonne() <<
                    " : Division par la variable '" <<
                    idfacteur->getId()->getNom() << "' qui vaut 0." << std::endl;
                    ret = false;
                }
            }
        }
    }
    return ret;
}


Expression *ExpressionDiv::simplifier(TableDesSymboles* tableDesSymboles) {
    if(this->facteur->estConstante(tableDesSymboles) && this->facteur->eval(tableDesSymboles) == ExpressionDiv::ELEMENT_NEUTRE){
        Expression* exp = (Expression*) this->terme;
        this->terme = nullptr;
        return exp;
    }
    else if(this->terme->estConstante(tableDesSymboles) && this->terme->eval(tableDesSymboles) == ExpressionDiv::ELEMENT_NEUTRE){
        Expression* exp = this->facteur;
        this->facteur = nullptr;
        return exp;
    }
    return nullptr;
}
