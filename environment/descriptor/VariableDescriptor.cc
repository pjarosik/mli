/**
 * IntegerDescriptor.cc
 *
 * @class IntegerDescriptor
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

#include "VariableDescriptor.h"

namespace matryca
{

VariableDescriptor::VariableDescriptor(const SymbolID &id, const Value &value) :
        value_(value), id_(id)
{
}

VariableDescriptor::~VariableDescriptor()
{
}

VariableDescriptor::Type VariableDescriptor::getType() const
{
    return SymbolDescriptor::VARIABLE;
}

void VariableDescriptor::setValue(const Value &value)
{
    value_ = value;
}

Value VariableDescriptor::getValue() const
{
    return value_;
}

Value VariableDescriptor::getValue(const Value & row, const Value & column)
{
    return value_.getElement(row, column);
}

VariableDescriptor::SymbolID VariableDescriptor::getSymbol() const
{
    return id_;
}

/* namespace matryca */
}

