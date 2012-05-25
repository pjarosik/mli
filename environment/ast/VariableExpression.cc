/**
 * VariableExpression.cc
 *
 * @class VariableExpression
 * @brief Brief description.
 * @author nieznany
 * @date 07-05-2012
 */

#include "VariableExpression.h"
#include "../exceptions/NotVariableException.h"

namespace matryca
{
VariableExpression::VariableExpression(const SymbolID & symbol) :
        symbol_(symbol)
{
}

VariableExpression::~VariableExpression()
{
}

VariableExpression::SymbolID VariableExpression::getID()
{
    return symbol_;
}

Value VariableExpression::doExecute(Environment & env)
{
    Environment::SymbolDescPtr desc = env.find(symbol_);
    if (desc->getType() != SymbolDescriptor::VARIABLE)
        throw NotVariableException(symbol_);
    VariableDescriptor::VarDescPtr var = boost::static_pointer_cast<VariableDescriptor>(desc);
    return var->getValue();
}

} /* namespace matryca */
