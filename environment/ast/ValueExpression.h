/**
 * ValueExpression.h
 *
 * @class ValueExpression
 * @brief Reprezentuje liczbe lub macierz w drzewie wyrazenia.
 * @author nieznany
 * @version APP_V.MODULE_V.CLASS_V
 * @date 07-05-2012
 */

#ifndef VALUEEXPRESSION_H_
#define VALUEEXPRESSION_H_

#include "Expression.h"

namespace matryca
{

class ValueExpression : public Expression
{
public:
    ValueExpression(int value);
    ValueExpression(double value);
//    ValueExpression(MatrixExpression m);
    virtual ~ValueExpression();
private:
    Value doExecute(Environment & env);
    Value value_;
};

} /* namespace matryca */
#endif /* VALUEEXPRESSION_H_ */
