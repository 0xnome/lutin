#ifndef LUTIN_BLOCDECLARATION_H
#define LUTIN_BLOCDECLARATION_H

#include "Symbole.h"
#include "Programme.h"

class BlocDeclarations : public Symbole
{
public:
  BlocDeclarations();
  ~BlocDeclarations();
protected:
  BlocDeclaration* suivant;
  Programme* programme;
};


#endif