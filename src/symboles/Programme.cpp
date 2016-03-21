#include <TableDesSymboles.h>
#include <easyloggingpp.h>
#include "Programme.h"


Programme::Programme(BlocDeclaration *blocDeclaration, BlocInstruction *blocInstruction) : Symbole(PROGRAMME),
                                                                                           blocDeclaration(
                                                                                                   blocDeclaration),
                                                                                           blocInstruction(
                                                                                                   blocInstruction) {
}

Programme::~Programme() {
    delete this->blocDeclaration;
    delete this->blocInstruction;
}

void Programme::executer(TableDesSymboles *tableDesSymboles) {
    LOG(INFO) << "Programme::execute";
    if (!blocDeclaration->estVide()) {
        BlocDeclaration *declarationCur;
        declarationCur = blocDeclaration;

        declarationCur->executer(tableDesSymboles);

        while (declarationCur->getSuivant() != nullptr) {
            declarationCur = declarationCur->getSuivant();
            declarationCur->executer(tableDesSymboles);
        }
    }

    if (!blocInstruction->estVide()) {
        BlocInstruction *instructionCur;
        instructionCur = blocInstruction;

        instructionCur->executer(tableDesSymboles);

        while (instructionCur->getSuivant() != nullptr) {
            instructionCur = instructionCur->getSuivant();
            instructionCur->executer(tableDesSymboles);
        }
    }
    return;
}

void Programme::afficher() {

    if (!blocDeclaration->estVide()) {
        BlocDeclaration *declarationCur;
        declarationCur = blocDeclaration;

        declarationCur->afficher();

        while (declarationCur->getSuivant() != nullptr) {
            declarationCur = declarationCur->getSuivant();
            declarationCur->afficher();
        }
    }

    if (!blocInstruction->estVide()) {
        BlocInstruction *instructionCur;
        instructionCur = blocInstruction;

        instructionCur->afficher();

        while (instructionCur->getSuivant() != nullptr) {
            instructionCur = instructionCur->getSuivant();
            instructionCur->afficher();
        }
    }
    return;
}

void Programme::analyser(TableDesSymboles *tableDesSymboles)
{
    if (!blocDeclaration->estVide())
    {
        BlocDeclaration* declarationCur;
        declarationCur = blocDeclaration;

        declarationCur->analyser(tableDesSymboles);

        while(declarationCur->getSuivant() != nullptr){
            declarationCur = declarationCur->getSuivant();
            declarationCur->analyser(tableDesSymboles);
        }
    }

    if (!blocInstruction->estVide())
    {
        BlocInstruction* instructionCur;
        instructionCur = blocInstruction;

        instructionCur->analyser(tableDesSymboles);

        while(instructionCur->getSuivant() != nullptr){
            instructionCur = instructionCur->getSuivant();
            instructionCur->analyser(tableDesSymboles);
        }
    }
    return;
}

void Programme::optimiser() {
    return;
}

Programme::Programme(int id) : Symbole(id)
{

}
