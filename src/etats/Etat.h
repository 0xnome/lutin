#ifndef LUTIN_ETAT_H
#define LUTIN_ETAT_H

#include <string>

class Etat
{
public:

    Etat(std::string nom);

    virtual ~Etat();

    void print() const;

    virtual bool transition(Automate &automate, Symbole *s) = 0;

protected:
    std::string nom;
};


class Etat0:Etat
{
public:
    Etat0() : Etat("E0")
    { }

};


#endif //LUTIN_ETAT_H
