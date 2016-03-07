#ifndef LUTIN_ETAT_H
#define LUTIN_ETAT_H

#include <string>
#include <iostream>

#include "Automate.h"
#include "Symbole.h"


class Automate;
class EtatInterface
{
public:

    EtatInterface(std::string nom) : nom(nom) {}

    virtual ~EtatInterface() = 0;

    std::ostream &operator<<(std::ostream& os) {
        return os << this->nom;
    }

    virtual bool transition(Automate* automate, Symbole *s) = 0;

protected:
    std::string nom;
};


class Etat : public EtatInterface
{
public:

    Etat(std::string nom) : EtatInterface(nom)
    { }

    ~Etat();

    virtual bool transition(Automate* automate, Symbole* s);

protected:
    std::string nom;
};

class EtatFin: public Etat
{
public:
    EtatFin() : Etat("EFin")
    { }
};

class Etat0: public Etat
{
public:
    Etat0() : Etat("E0")
    { }
    virtual bool transition(Automate* automate, Symbole* s);
};

class Etat1: public Etat
{
public:
    Etat1() : Etat("E1")
    { }
    virtual bool transition(Automate* automate, Symbole* s);
};

class Etat2: public Etat
{
public:
    Etat2() : Etat("E2")
    { }
    virtual bool transition(Automate* automate, Symbole* s);
};

class Etat3: public Etat
{
public:
    Etat3() : Etat("E3")
    { }
    virtual bool transition(Automate* automate, Symbole* s);
};

class Etat4: public Etat
{
public:
    Etat4() : Etat("E4")
    { }
};

class Etat5: public Etat
{
public:
    Etat5() : Etat("E5")
    { }
};

class Etat6: public Etat
{
public:
    Etat6() : Etat("E6")
    { }
};

class Etat7: public Etat
{
public:
    Etat7() : Etat("E7")
    { }
};

class Etat8: public Etat
{
public:
    Etat8() : Etat("E8")
    { }
};

class Etat9: public Etat
{
public:
    Etat9() : Etat("E9")
    { }
};

class Etat28: public Etat
{
public:
    Etat28() : Etat("E28")
    { }
    virtual bool transition(Automate* automate, Symbole* s);
};

#endif //LUTIN_ETAT_H
