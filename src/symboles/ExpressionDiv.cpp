#include <easyloggingpp.h>
#include "ExpressionDiv.h"
#include "ConstanteNumerique.h"

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
            std::cout << "Division par 0 à la ligne " << constante->getLigne() << std::endl;
        }
    }
}
