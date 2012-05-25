/**
 * MatrixElementExpression.h
 *
 * @class MatrixElementExpression
 * @brief Brief description.
 * @author nieznany
 * @date 12-05-2012
 */

#ifndef MATRIXELEMENTEXPRESSION_H_
#define MATRIXELEMENTEXPRESSION_H_
#include "Expression.h"
#include "../descriptor/VariableDescriptor.h"

namespace matryca
{

class MatrixElementExpression : public Expression
{
public:
    typedef Expression::ExpressionPtr ExpressionPtr;
    typedef SymbolDescriptor::SymbolID SymbolID;
    typedef SymbolDescriptor::SymbolDescPtr SymbolDescPtr;
    typedef VariableDescriptor::VarDescPtr VarDescPtr;

    MatrixElementExpression(const SymbolID &id, ExpressionPtr first, ExpressionPtr second);
    virtual ~MatrixElementExpression();
private:
    Value doExecute(Environment &env);

    SymbolID symbol_;
    ExpressionPtr first_, second_;
};

} /* namespace matryca */
#endif /* MATRIXELEMENTEXPRESSION_H_ */
