#include <easyloggingpp.h>
#include "ExpressionMult.h"
#include "ConstanteNumerique.h"

using namespace std;

ExpressionMult::ExpressionMult(Facteur *facteur, Terme *terme) : Terme(EXPRESSION_MULT), facteur(facteur),
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


Expression *ExpressionMult::simplifier(TableDesSymboles* tableDesSymboles) {
    if(this->facteur->estConstante(tableDesSymboles) && this->facteur->eval(tableDesSymboles) == ExpressionMult::ELEMENT_NEUTRE){
        Expression* exp = (Expression*) this->terme;
        this->terme = nullptr;
        return exp;
    }
    else if(this->terme->estConstante(tableDesSymboles) && this->terme->eval(tableDesSymboles) == ExpressionMult::ELEMENT_NEUTRE){
        Expression* exp = this->facteur;
        this->facteur = nullptr;
        return exp;
    }
    return nullptr;
}

bool ExpressionMult::analyser(TableDesSymboles *tableDesSymboles)
{
    return this->facteur->analyser(tableDesSymboles) &
           this->terme->analyser(tableDesSymboles);
}
