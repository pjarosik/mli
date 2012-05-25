/**
 * VariableExpression.h
 *
 * @class VariableExpression
 * @brief Wezel w AST reprezentujacy dostep do zmiennej.
 * @author nieznany
 * @date 07-05-2012
 */

#ifndef VARIABLEEXPRESSION_H_
#define VARIABLEEXPRESSION_H_

#include "Expression.h"
#include "../Environment.h"
#include "../descriptor/VariableDescriptor.h"

namespace matryca
{

class VariableExpression : public Expression
{
public:
    typedef Environment::SymbolID SymbolID;
    typedef VariableDescriptor::VarDescPtr VarDescPtr;

    VariableExpression(const SymbolID &symbol);
    SymbolID getID();
    virtual ~VariableExpression();
private:
    Value doExecute(Environment &env);
    SymbolID symbol_;
};

} /* namespace matryca */
#endif /* VARIABLEEXPRESSION_H_ */
