#ifndef LUTIN_EXPRESSIONPARENTHESEE_H
#define LUTIN_EXPRESSIONPARENTHESEE_H

#include "Facteur.h"

class ExpressionParenthesee : public Facteur
{

public:
    ExpressionParenthesee(Expression *expression);

    ~ExpressionParenthesee();

    virtual void afficher();

    virtual int eval(TableDesSymboles *tablesDesSymboles);

    virtual void executer(TableDesSymboles *tableDesSymboles);

    virtual void analyser(TableDesSymboles *tableDesSymboles);

    virtual bool estConstante(TableDesSymboles *tableDesSymboles);


protected:
    Expression *expression;
};


#endif //LUTIN_EXPRESSIONPARENTHESEE_H
