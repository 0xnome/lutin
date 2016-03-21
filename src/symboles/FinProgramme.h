#ifndef LUTIN_FINPROGRAMME_H
#define LUTIN_FINPROGRAMME_H


#include "Symbole.h"

class FinProgramme : public Symbole
{
public:
    FinProgramme() : Symbole(FIN_PROGRAMME)
    { }

    ~FinProgramme()
    { }


    virtual void analyser(TableDesSymboles *tableDesSymboles)
    { };
};


#endif //LUTIN_FINPROGRAMME_H
