#include "InstructionLecture.h"

using namespace std;


InstructionLecture::InstructionLecture(IdTerminal *idTerminal) : BlocInstruction(INSTRUCTION_LECTURE), id(idTerminal)
{
}

InstructionLecture::~InstructionLecture()
{
    if (this->id != nullptr)
    {
        delete this->id;
    }
}

void InstructionLecture::afficher()
{
    cout << "lire ";
    this->id->afficher();
    cout << ";" << endl;
}

void InstructionLecture::executer(TableDesSymboles *tableDesSymboles)
{
    int val;
    cin >> val;

    while (std::cin.fail())
    {
        std::cout << "Vous devez rentrer un Entier..." << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> val;
    }

    tableDesSymboles->setVariableValeur(id->getNom(), val);
}

bool InstructionLecture::estVide()
{
    return this->id == nullptr;
}


void InstructionLecture::optimiser()
{
    return;
}

bool InstructionLecture::analyser(TableDesSymboles *tableDesSymboles)
{
    if (tableDesSymboles->estDeclaree(id->getNom()))
    {
        if (tableDesSymboles->estConstante(id->getNom()))
        {
            std::cerr << "Erreur ligne " << this->id->getLigne() << " : " << this->id->getNom() <<
            " est une constante et ne peut etre modifiée " << std::endl;
            return false;
        } else
        {
            tableDesSymboles->estInitialisee(id->getNom());
        }
    } else
    {
        std::cerr << "Erreur ligne " << this->id->getLigne() << " : " << this->id->getNom() <<
        " n'a pas été déclarée." << std::endl;
        return false;
    }

    tableDesSymboles->setInitialisee(id->getNom());
    return true;
}

void InstructionLecture::optimiser(TableDesSymboles *tableDesSymboles)
{
    tableDesSymboles->setInitialisee(id->getNom());
}
