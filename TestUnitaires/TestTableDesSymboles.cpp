#include <assert.h>
#include <string>


#include "TableDesSymboles.h"

using namespace std;

void testAjouterConstante()
{
    TableDesSymboles tableDesSymboles;

    string constString1("constVar");

    tableDesSymboles.ajouterConstante(constString1, 46);
    assert(tableDesSymboles.getNbConstante() == 1);
    assert(tableDesSymboles.getConstanteValeur(constString1) == 46);


    // ajout d'une constante de mm nom
    tableDesSymboles.ajouterConstante(constString1, 42);
    assert(tableDesSymboles.getNbConstante() == 1);
    assert(tableDesSymboles.getConstanteValeur(constString1) == 46);


}

void testEstUtiliseeConstante()
{
    TableDesSymboles tableDesSymboles;
    string constString1("constVar");

    tableDesSymboles.ajouterConstante(constString1, 46);
    tableDesSymboles.setConstanteUtilisee(constString1);

    //assert(tableDesSymboles.)

}

void testEstInitialiseeEstUtiliseeVariable()
{
    TableDesSymboles tableDesSymboles;
    string variable("variable");

    tableDesSymboles.ajouterVariable(variable);

    assert(tableDesSymboles.getNbVariable() == 1);

    assert(!tableDesSymboles.estInitialisee(variable));
    assert(!tableDesSymboles.estUtiliseeVariable(variable));

}


void testAjouterVariable()
{
    TableDesSymboles tableDesSymboles;
    string variable("variable");

    tableDesSymboles.ajouterVariable(variable);

    assert(tableDesSymboles.getNbVariable() == 1);

    tableDesSymboles.setVariableValeur(variable,42);
    assert(tableDesSymboles.getVariableValeur(variable) == 42);
}


int main(int argc, char **argv)
{
    testAjouterConstante();
    testAjouterVariable();
    testEstInitialiseeEstUtiliseeVariable();
    testEstUtiliseeConstante();
    return 0;
}