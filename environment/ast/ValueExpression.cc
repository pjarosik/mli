/**
 * ValueExpression.cc
 *
 * @class ValueExpression
 * @brief Brief description.
 * @author nieznany
 * @date 07-05-2012
 */

#include "ValueExpression.h"

namespace matryca
{

ValueExpression::ValueExpression(int value) :
        value_(value)
{
}

ValueExpression::ValueExpression(double value) :
        value_(value)
{
}

ValueExpression::~ValueExpression()
{
}

Value ValueExpression::doExecute(Environment & env)
{
    return value_;
}

} /* namespace matryca */
