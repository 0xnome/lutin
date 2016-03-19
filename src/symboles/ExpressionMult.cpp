#include <easyloggingpp.h>
#include "ExpressionMult.h"

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

void ExpressionMult::analyser(TableDesSymboles *tableDesSymboles)
{

}
