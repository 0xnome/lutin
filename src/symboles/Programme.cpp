#include "Programme.h"


Programme::Programme(BlocDeclaration *blocDeclaration, BlocInstruction *blocInstruction) : Symbole(PROGRAMME)
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
    if (blocDeclaration != nullptr) {
        blocDeclaration->afficher();
    }
    if (blocInstruction != nullptr) {
        blocInstruction->afficher();
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
