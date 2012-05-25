/**
 * MatrixElementExpression.cc
 *
 * @class MatrixElementExpression
 * @brief Brief description.
 * @author nieznany
 * @date 12-05-2012
 */

#include "MatrixElementExpression.h"
#include "../exceptions/NotVariableException.h"
#include <stdexcept>

using namespace std;

namespace matryca
{

MatrixElementExpression::MatrixElementExpression(const SymbolID &id, ExpressionPtr first, ExpressionPtr second) :
        symbol_(id), first_(first), second_(second)
{
}

MatrixElementExpression::~MatrixElementExpression()
{
}
// powinna zawsze zwracac double
Value MatrixElementExpression::doExecute(Environment & env)
{
    if(!first_ || !second_)
        throw runtime_error("MatrixElementExpression::doExecute: pusty wskaznik do wyrazenia");

    SymbolDescPtr desc = env.find(symbol_);
    if (desc->getType() != SymbolDescriptor::VARIABLE)
        throw NotVariableException(symbol_);
    VariableDescriptor::VarDescPtr var = boost::static_pointer_cast<VariableDescriptor>(desc);

    Value row = first_->execute(env);
    Value column = second_->execute(env);
    return var->getValue(row, column);
}

} /* namespace matryca */
