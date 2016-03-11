#ifndef LUTIN_ETATDEFAUT_H
#define LUTIN_ETATDEFAUT_H

#include <string>
#include <iostream>

#include "Automate.h"
#include "Symbole.h"
#include "EtatInterface.h"

class EtatDefaut : public EtatInterface
{
public:

    EtatDefaut(std::string nom) : EtatInterface(nom){ }

    virtual ~EtatDefaut(){};

    virtual bool transition(Automate* automate, Symbole* s);
};
/*
class Etat0: public EtatDefaut
{
public:
    Etat0() : EtatDefaut("E0")
    { }
    virtual bool transition(Automate* automate, Symbole* s);
};

class Etat1: public EtatDefaut
{
public:
    Etat1() : EtatDefaut("E1")
    { }
    virtual bool transition(Automate* automate, Symbole* s);
};

class Etat2: public EtatDefaut
{
public:
    Etat2() : EtatDefaut("E2")
    { }
    virtual bool transition(Automate* automate, Symbole* s);
};

class Etat3: public EtatDefaut
{
public:
    Etat3() : EtatDefaut("E3")
    { }
    virtual bool transition(Automate* automate, Symbole* s);
};

class Etat4: public EtatDefaut
{
public:
    Etat4() : EtatDefaut("E4")
    { }
};

class Etat5: public EtatDefaut
{
public:
    Etat5() : EtatDefaut("E5")
    { }
};

class Etat6: public EtatDefaut
{
public:
    Etat6() : EtatDefaut("E6")
    { }
};

class Etat7: public EtatDefaut
{
public:
    Etat7() : EtatDefaut("E7")
    { }
};

class Etat8: public EtatDefaut
{
public:
    Etat8() : EtatDefaut("E8")
    { }
};

class Etat9: public EtatDefaut
{
public:
    Etat9() : EtatDefaut("E9")
    { }
};

class Etat28: public EtatDefaut
{
public:
    Etat28() : EtatDefaut("E28")
    { }
    virtual bool transition(Automate* automate, Symbole* s);
};
*/
#endif //LUTIN_ETATDEFAUT_H
