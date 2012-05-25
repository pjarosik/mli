/**
 * MatrixExpression.h
 *
 * @class MatrixExpression
 * @brief Brief description.
 * @author nieznany
 * @date 12-05-2012
 */

#ifndef MATRIXEXPRESSION_H_
#define MATRIXEXPRESSION_H_

#include "Expression.h"
#include <list>

namespace matryca
{

class MatrixExpression : public Expression
{
public:
    typedef Expression::ExpressionPtrList ExpressionPtrList;
    // lista list wyrazen
    typedef Expression::ExpressionPtrMatrix ExpressionPtrMatrix;
    MatrixExpression(const ExpressionPtrMatrix &matrix);
    virtual ~MatrixExpression();
private:
    /**
     * @param env
     * @return wynikowa macierz
     */
    Value doExecute(Environment &env);
    ExpressionPtrMatrix matrix_;
};

} /* namespace matryca */
#endif /* MATRIXEXPRESSION_H_ */
