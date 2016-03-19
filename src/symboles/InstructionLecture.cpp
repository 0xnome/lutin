#include "InstructionLecture.h"

using namespace std;


InstructionLecture::InstructionLecture(IdTerminal *idTerminal) : BlocInstruction(INSTRUCTION_LECTURE), id(idTerminal) {
}

InstructionLecture::~InstructionLecture() {
    if (this->id != nullptr) {
        delete this->id;
    }
}

void InstructionLecture::afficher() {
    cout << "lire ";
    this->id->afficher();
    cout << ";" << endl;
}

void InstructionLecture::executer(TableDesSymboles *tableDesSymboles) {
    // todo vérif sur la valeur d'entrée ? int, negatif, ... à voir
    int val;
    cin >> val;
    tableDesSymboles->setVariableValeur(id->getNom(), val);
}

bool InstructionLecture::estVide() {
    return this->id == nullptr;
}


void InstructionLecture::optimiser() {

}

void InstructionLecture::analyser(TableDesSymboles *tableDesSymboles)
{

}
