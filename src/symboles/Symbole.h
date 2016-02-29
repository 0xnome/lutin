#ifndef LUTIN_SYMBOLE_H
#define LUTIN_SYMBOLE_H

enum SYMBOLES
{
    PROGRAMME = 0,
    DECLARATION_CONSTANTES = 1
};


class Symbole
{
protected:
    int identifiant;
public:
    Symbole(int id) : identifiant(id)
    { }

    virtual ~Symbole()
    { }

    void print();

    operator int() const
    { return identifiant; }
};


#endif
