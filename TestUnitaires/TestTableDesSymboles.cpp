#include <assert.h>
#include <string>


#include "TableDesSymboles.h"

using namespace std;

const unsigned ligne = 0;
const unsigned colonne = 0;

void testAjouterConstante()
{
    TableDesSymboles tableDesSymboles;

    string constString1("constVar");

    tableDesSymboles.ajouterConstante(constString1, ligne, colonne, 46);
    assert(tableDesSymboles.getNbConstante() == 1);
    assert(*tableDesSymboles.getConstanteValeur(constString1) == 46);


    // ajout d'une constante de mm nom
    //tableDesSymboles.ajouterConstante(constString1, 42);
    assert(tableDesSymboles.getNbConstante() == 1);
    assert(*tableDesSymboles.getConstanteValeur(constString1) == 46);


}

void testEstUtiliseeConstante()
{
    TableDesSymboles tableDesSymboles;
    string constString1("constVar");

    tableDesSymboles.ajouterConstante(constString1,ligne,colonne, 46);
    tableDesSymboles.setConstanteUtilisee(constString1);


}

void testEstInitialiseeEstUtiliseeVariable()
{
    TableDesSymboles tableDesSymboles;
    string variable("variable");

    tableDesSymboles.ajouterVariable(variable,ligne,colonne);

    assert(tableDesSymboles.getNbVariable() == 1);

    assert(!tableDesSymboles.estInitialisee(variable));
    assert(!tableDesSymboles.estUtiliseeVariable(variable));

    assert(tableDesSymboles.getVariableValeur(variable) == nullptr);
    tableDesSymboles.setVariableUtilisee(variable);
    assert(tableDesSymboles.estUtiliseeVariable(variable));

    tableDesSymboles.setVariableValeur(variable,42);
    assert(*tableDesSymboles.getValeur(variable) == 42);
    assert(tableDesSymboles.estInitialisee(variable));

    tableDesSymboles.setInitialisee(variable);
    assert(tableDesSymboles.getValeur(variable) == nullptr);
    assert(tableDesSymboles.estInitialisee(variable));

}


void testAjouterVariable()
{
    TableDesSymboles tableDesSymboles;
    string variable("variable");

    tableDesSymboles.ajouterVariable(variable,ligne,colonne);

    assert(tableDesSymboles.getNbVariable() == 1);

    tableDesSymboles.setVariableValeur(variable, 42);
    //assert(tableDesSymboles.getVariableValeur(variable) == 42);
}


/**
 *
 */
void testEstDeclaree()
{
    TableDesSymboles tableDesSymboles;
}



int main(int argc, char **argv)
{
    testAjouterConstante();
    testAjouterVariable();
    testEstInitialiseeEstUtiliseeVariable();
    testEstUtiliseeConstante();
    testEstDeclaree();
    return 0;
}