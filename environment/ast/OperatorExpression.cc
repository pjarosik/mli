/**
 * ArithmeticExpression.cc
 *
 * @class ArithmeticExpression
 * @brief Brief description.
 * @author nieznany
 * @date 07-05-2012
 */

#include "OperatorExpression.h"
#include "../exceptions/UnknownOperatorException.h"
namespace matryca
{

OperatorExpression::OperatorExpression(const ArithmeticOperator & op, ExpressionPtr left, ExpressionPtr right) :
        operator_(op), left_(left), right_(right)
{
}

OperatorExpression::~OperatorExpression()
{
}

Value OperatorExpression::doExecute(Environment & env)
{
    if(!left_ && !right_)
    { // oba liscie puste - nie powinno sie to zdarzyc
        throw new EnvironmentException("wyrazenie operatorowe bez ustawionych dzieci (left_ NULL i right_ NULL)");
    }
    if(!left_)
    { // tylko lewe poddrzewo puste
        return right_->execute(env);
    }
    if(!right_)
    { // tylko prawe poddrzewo puste
        return left_->execute(env);
    }
    Value l_val = left_->execute(env);
    Value r_val = right_->execute(env);
    // FIXME zrobic to ponizej ladniej
    if (operator_ == '+')
        return l_val+r_val;
    else if (operator_ == '-')
        return l_val-r_val;
    else if (operator_ == '*')
        return l_val*r_val;
    else if (operator_ == '/')
        return l_val/r_val;
    else if (operator_ == '>')
        return l_val > r_val ? 1 : 0;
    else if (operator_ == 'g')
        return l_val >= r_val ? 1 : 0;
    else if (operator_ == '<')
        return l_val < r_val ? 1 : 0;
    else if (operator_ == 'l')
        return l_val <= r_val ? 1 : 0;
    else if (operator_ == '=')
        return l_val == r_val ? 1 : 0;
    else if (operator_ == '!')
        return l_val != r_val ? 1 : 0;
    else if (operator_ == 'o')
        return (l_val != Value(0) || r_val != Value(0)) ? 1 : 0;
    else if (operator_ == 'a')
        return (l_val != Value(0) && r_val != Value(0)) ? 1 : 0;
    else if (operator_ == 'n') // w przypadku NOT  argumentem jest R_VAL
        return r_val != Value(0) ? 1: 0;
    else throw UnknownOperatorException(std::string(&operator_));
}

} /* namespace matryca */
