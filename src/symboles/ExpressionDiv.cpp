#include "ExpressionDiv.h"


using namespace std;

ExpressionDiv::ExpressionDiv(Facteur *facteur, Terme *terme) : Terme(EXPRESSION_DIV), terme(terme), facteur(facteur) {
}

ExpressionDiv::~ExpressionDiv() {
    delete this->terme;
    delete this->facteur;
}

void ExpressionDiv::afficher() {
    this->terme->afficher();
    cout << "/";
    this->facteur->afficher();
}

void ExpressionDiv::executer(TableDesSymboles *tableDesSymboles) {

}

int ExpressionDiv::eval(TableDesSymboles *tablesDesSymboles) {
    // TODO division par 0  ?
    return facteur->eval(tablesDesSymboles) / terme->eval(tablesDesSymboles);
}
