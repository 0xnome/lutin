#include "Programme.h"


Programme::Programme(int id, BlocDeclaration *blocDeclaration, BlocInstruction *blocInstruction) : Symbole(id)
{
    this->blocInstruction = blocInstruction;
    this->blocDeclaration = blocDeclaration;
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
