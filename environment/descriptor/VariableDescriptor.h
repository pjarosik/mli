/**
 * IntegerDescriptor.h
 *
 * @class IntegerDescriptor
 * @brief Brief description.
 * @author nieznany
 * @date 06-05-2012
 */

#ifndef INTEGERDESCRIPTOR_H_
#define INTEGERDESCRIPTOR_H_

#include <boost/shared_ptr.hpp>
#include "SymbolDescriptor.h"
#include "../data/Value.h"

namespace matryca
{

class VariableDescriptor : public SymbolDescriptor
{
public:
    // typedefs
    typedef SymbolDescriptor::Type Type;
    typedef SymbolDescriptor::SymbolID SymbolID;
    typedef boost::shared_ptr<VariableDescriptor> VarDescPtr;
    VariableDescriptor(const SymbolID &id, const Value &value);
    virtual ~VariableDescriptor();

    Type getType() const;
    void setValue(const Value &value);
    Value getValue() const;
    Value getValue(const Value &row, const Value &column);
    SymbolID getSymbol() const;
private:
    SymbolID id_;
    Value value_;
};

} /* namespace matryca */
#endif /* INTEGERDESCRIPTOR_H_ */
