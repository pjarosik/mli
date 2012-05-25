/**
 *
 * @class OperatorExpression
 * @brief Brief description.
 * @author nieznany
 * @date 07-05-2012
 */

#ifndef OPERATOREXPRESSION_H_
#define OPERATOREXPRESSION_H_
#include "Expression.h"
#include "../data/Value.h"

#include <string>
namespace matryca
{

class OperatorExpression : public Expression
{
public:
    typedef char ArithmeticOperator;
    OperatorExpression(const ArithmeticOperator &op, ExpressionPtr left, ExpressionPtr right);
    virtual ~OperatorExpression();
private:
    Value doExecute(Environment &env);

    ExpressionPtr left_, right_;
    ArithmeticOperator operator_;
};

} /* namespace matryca */
#endif /* OPERATOREXPRESSION_H_ */
