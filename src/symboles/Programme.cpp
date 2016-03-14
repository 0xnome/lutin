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

void Programme::executer()
{
    return;
}

void Programme::afficher()
{

    if (blocDeclaration != nullptr)
    {
        BlocDeclaration* declarationCur;
        declarationCur = blocDeclaration;

        declarationCur->afficher();

        while(declarationCur->getSuivant() != nullptr){
            declarationCur = declarationCur->getSuivant();
            declarationCur->afficher();
        }
    }

    if (blocInstruction != nullptr)
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
