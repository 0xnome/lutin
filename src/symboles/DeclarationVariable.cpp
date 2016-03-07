#include "DeclarationVariable.h"

void DeclarationVariable::afficher()
{
    Identificateur * id_courant = &(this->id);
    while (id_courant != nullptr){
        std::cout << "var ";
        id_courant->afficher();
        std::cout << ';' <<std::endl;
        id_courant = id_courant->getSuivant();
    }
}
