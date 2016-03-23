#include <easyloggingpp.h>
#include "ExpressionMult.h"
#include "ConstanteNumerique.h"

using namespace std;

ExpressionMult::ExpressionMult(Facteur *facteur, Terme *terme) : Terme(EXPRESSION_MULT, terme->getLigne(), terme->getColonne()), facteur(facteur),
                                                                 terme(terme)
{
}

ExpressionMult::~ExpressionMult()
{
    delete this->terme;
    delete this->facteur;
}

void ExpressionMult::afficher()
{
    this->terme->afficher();
    cout << "*";
    this->facteur->afficher();
}

int ExpressionMult::eval(TableDesSymboles *tablesDesSymboles)
{
    LOG(INFO) << "ExpressionMult::eval";
    return (terme->eval(tablesDesSymboles) * facteur->eval(tablesDesSymboles));
}

void ExpressionMult::executer(TableDesSymboles *tableDesSymboles)
{

}

bool ExpressionMult::estConstante(TableDesSymboles *tableDesSymboles)
{
    return this->terme->estConstante(tableDesSymboles) && this->facteur->estConstante(tableDesSymboles);
}

void ExpressionMult::optimiser(TableDesSymboles *tableDesSymboles)
{
    this->facteur->optimiser(tableDesSymboles);
    // si facteur a une valeur connue et n'est pas déjà une constante numérique
    if (this->facteur->estConstante(tableDesSymboles) && (int) *(this->facteur) != CONSTANTE_NUMERIQUE)
    {
        int val = this->facteur->eval(tableDesSymboles);
        Facteur *fact = new ConstanteNumerique(
                new NumTerminal(val, this->facteur->getLigne(), this->facteur->getColonne()));
        delete this->facteur;
        this->facteur = fact;
    } else
    {
        // si on a pu remplacer par une constante numerique on tente une simplification
        Facteur *fac;
        fac = (Facteur *) this->facteur->simplifier(tableDesSymboles);
        if(fac != nullptr)
        {
            delete this->facteur;
            this->facteur = fac;
        }
    }

    this->terme->optimiser(tableDesSymboles);
    if (this->terme->estConstante(tableDesSymboles))
    {
        int val = this->terme->eval(tableDesSymboles);
        Terme *ter = new ConstanteNumerique(new NumTerminal(val, this->terme->getLigne(), this->terme->getColonne()));
        delete this->terme;
        this->terme = ter;
    } else
    {
        // si on a pu remplacer par une constante numerique on tente une simplification
        Terme *ter;
        ter = (Terme *) this->terme->simplifier(tableDesSymboles);
        if(ter != nullptr)
        {
            delete this->terme;
            this->terme = ter;
        }
    }
}


Expression *ExpressionMult::simplifier(TableDesSymboles* tableDesSymboles) {
    // terme * facteur
        // terme * 1 = terme
    if(this->facteur->estConstante(tableDesSymboles) && this->facteur->eval(tableDesSymboles) == ExpressionMult::ELEMENT_NEUTRE){
        Expression* exp = (Expression*) this->terme;
        this->terme = nullptr;
        return exp;
    }
        // terme * 0 = 0
    else if(this->facteur->estConstante(tableDesSymboles) && this->facteur->eval(tableDesSymboles) == ExpressionMult::ELEMENT_ABSORBANT){
        Expression* exp = (Expression*) new ConstanteNumerique(new NumTerminal(0, this->terme->getLigne(), this->terme->getColonne()));
        return exp;
    }
        // 1 * facteur = facteur
    else if(this->terme->estConstante(tableDesSymboles) && this->terme->eval(tableDesSymboles) == ExpressionMult::ELEMENT_NEUTRE){
        Expression* exp = this->facteur;
        this->facteur = nullptr;
        return exp;
    }
        // 0 * facteur = facteur
    else if(this->terme->estConstante(tableDesSymboles) && this->terme->eval(tableDesSymboles) == ExpressionMult::ELEMENT_ABSORBANT){
        Expression* exp = (Expression*) new ConstanteNumerique(new NumTerminal(0, this->facteur->getLigne(), this->facteur->getColonne()));
        return exp;
    }
    return nullptr;
}

bool ExpressionMult::analyser(TableDesSymboles *tableDesSymboles)
{
    return this->facteur->analyser(tableDesSymboles) &
           this->terme->analyser(tableDesSymboles);
}
