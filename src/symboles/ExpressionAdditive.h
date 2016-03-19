#ifndef LUTIN_EXPRESSIONADDITIVE_H
#define LUTIN_EXPRESSIONADDITIVE_H


#include "Expression.h"
#include "Terme.h"

class ExpressionAdditive : public Expression
{

public:
    ExpressionAdditive(Terme *terme1, Expression *expression1);

    ~ExpressionAdditive();

    void afficher();

    int eval(TableDesSymboles *tablesDesSymboles);

    void executer(TableDesSymboles *tableDesSymboles);

    void analyser(TableDesSymboles *tableDesSymboles);

protected:

    Terme *terme;

    Expression *expression;

};


#endif //LUTIN_EXPRESSIONADDITIVE_H
