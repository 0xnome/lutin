#include <TableDesSymboles.h>
#include "Programme.h"


Programme::Programme(BlocDeclaration *blocDeclaration, BlocInstruction *blocInstruction) : Symbole(PROGRAMME)
{
    this->blocDeclaration = blocDeclaration;
    this->blocInstruction = blocInstruction;
}

Programme::~Programme()
{
    delete this->blocDeclaration;
    delete this->blocInstruction;
}

void Programme::executer(TableDesSymboles *tableDesSymboles)
{
    if (blocDeclaration != nullptr)
    {
        BlocDeclaration* declarationCur;
        declarationCur = blocDeclaration;

        declarationCur->executer(tableDesSymboles);

        while(declarationCur->getSuivant() != nullptr){
            declarationCur = declarationCur->getSuivant();
            declarationCur->executer(tableDesSymboles);
        }
    }

    if (blocInstruction != nullptr)
    {
        BlocInstruction* instructionCur;
        instructionCur = blocInstruction;

        instructionCur->executer(tableDesSymboles);

         while(instructionCur->getSuivant() != nullptr){
            instructionCur = instructionCur->getSuivant();
            instructionCur->executer(tableDesSymboles);
        }
    }
    return;
}

void Programme::afficher()
{

    if (!blocDeclaration->estVide())
    {
        BlocDeclaration* declarationCur;
        declarationCur = blocDeclaration;

        declarationCur->afficher();

        while(declarationCur->getSuivant() != nullptr){
            declarationCur = declarationCur->getSuivant();
            declarationCur->afficher();
        }
    }

    if (!blocInstruction->estVide())
    {
        BlocInstruction* instructionCur;
        instructionCur = blocInstruction;

        instructionCur->afficher();

         while(instructionCur->getSuivant() != nullptr){
            instructionCur = instructionCur->getSuivant();
            instructionCur->afficher();
        }
    }
    return;
}

void Programme::analyser()
{
    return;
}

void Programme::optimiser()
{
    return;
}
