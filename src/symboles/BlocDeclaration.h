#ifndef LUTIN_BLOCDECLARATION_H
#define LUTIN_BLOCDECLARATION_H

#include "Symbole.h"

class BlocDeclaration : public Symbole
{
public:
  BlocDeclaration();
  ~BlocDeclaration();
protected:
  BlocDeclaration* suivant;
};


#endif